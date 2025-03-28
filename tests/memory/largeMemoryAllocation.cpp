#pragma once

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <memoryapi.h>

#define SE_LOCK_MEMORY_NAME TEXT("SeLockMemoryPrivilege")

const size_t MaxAllocs = 12000;
// void* pMem[MaxAllocs];  // Global array to track allocations


// Function to get Query Performance Counter
__int64 GetQPC()
{
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);
    return time.QuadPart;
}

// Function to get Query Performance Frequency
double GetQPF()
{
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return static_cast<double>(frequency.QuadPart);
}

void* pMem[MaxAllocs] = { 0 };

// Function to enable a specific privilege in the current process
bool EnablePrivilege(LPCTSTR pszPrivilege)
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tp;
    LUID luid;

    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
    {
        printf("OpenProcessToken failed. Error: %u\n", GetLastError());
        return false;
    }

    if (!LookupPrivilegeValue(NULL, pszPrivilege, &luid))
    {
        printf("LookupPrivilegeValue failed. Error: %u\n", GetLastError());
        CloseHandle(hToken);
        return false;
    }

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Luid = luid;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!AdjustTokenPrivileges(hToken, FALSE, &tp, sizeof(tp), NULL, NULL))
    {
        printf("AdjustTokenPrivileges failed. Error: %u\n", GetLastError());
        CloseHandle(hToken);
        return false;
    }

    if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
    {
        printf("The token does not have the specified privilege.\n");
        CloseHandle(hToken);
        return false;
    }

    CloseHandle(hToken);
    return true;
}

void TimeAllocMemoryWithParams(bool topDown, const size_t pageSizeBytes, size_t count, bool useLargePages)
{
    // Runtime check instead of assert
    if (count > MaxAllocs)
    {
        printf("Error: count (%zu) exceeds MaxAllocs (%zu)\n", count, MaxAllocs);
        return;
    }
    DWORD flags = MEM_RESERVE | MEM_COMMIT;
    if (topDown)
        flags |= MEM_TOP_DOWN;
    if (useLargePages)
        flags |= MEM_LARGE_PAGES;

    // For MEM_LARGE_PAGES, the allocation size must be multiples of the system's large page size
    if (useLargePages)
    {
        size_t largePageSize = GetLargePageMinimum();
        if (pageSizeBytes % largePageSize != 0)
        {
            printf("Allocation size must be a multiple of the large page size (%zu bytes).\n", largePageSize);
            return;
        }
    }

    assert(count <= MaxAllocs);

    __int64 start = GetQPC();
    for (size_t i = 0; i < count; ++i)
    {
        pMem[i] = VirtualAlloc(NULL, pageSizeBytes, flags, PAGE_READWRITE);
        if (pMem[i] == NULL)
        {
            printf("VirtualAlloc failed. Error: %u\n", GetLastError());
            return;
        }
        else
        {
           // printf("Allocated memory at address: %p for index %zu\n", pMem[i], i);
        }
    }
    __int64 elapsed = GetQPC() - start;

    printf(" %s allocs took %7.4f s for %5lld allocs of %lld KB blocks (total is %lld MB).\n",
        useLargePages ? (topDown ? "Topdown with Large Pages" : "Normal with Large Pages") : (topDown ? "Topdown" : "Normal"),
        static_cast<double>(elapsed) / GetQPF(),
        static_cast<long long>(count),
        static_cast<long long>(pageSizeBytes) / 1024,
        static_cast<long long>(count * pageSizeBytes) / (1024 * 1024));

    // printf("Free the memory after each allocation.\n");
    for (size_t i = 0; i < count; ++i)
    {
        if (pMem[i])
            VirtualFree(pMem[i], 0, MEM_RELEASE);
        pMem[i] = NULL;
    }
}


int main(int argc, char* argv[])
{
    printf("Starting MemoryAllocation test.\n");

    // Get system memory info
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    const size_t regularPageSize = sysInfo.dwPageSize;
    const size_t largePageSize = GetLargePageMinimum();

    // Enable privileges only if needed for large pages
    bool hasLargePageAccess = true;
    if (largePageSize > 0)
    {
        hasLargePageAccess = EnablePrivilege(SE_LOCK_MEMORY_NAME);
    }

    // Test configurations: {useLargePages, topDown}
    const bool testConfigs[4][2] = {
        {true, false},   // Large pages + normal
        {true, true},    // Large pages + top-down
        {false, false},  // Regular pages + normal
        {false, true},   // Regular pages + top-down
    };

    for (int cfg = 0; cfg < 4; ++cfg)
    {
        const bool useLargePages = testConfigs[cfg][0];
        const bool topDown = testConfigs[cfg][1];

        // Skip invalid large page configs
        if (useLargePages && (largePageSize == 0 || !hasLargePageAccess))
        {
            printf("\nSkipping large pages - not available\n");
            continue;
        }

        // Configure parameters
        const size_t pageSize = useLargePages ? largePageSize : regularPageSize;
        const char* modeStr = topDown ? "TopDown" : "Normal";
        const char* pageStr = useLargePages ? "Large" : "Regular";

        printf("\n--- Testing %s allocation with %s pages (%zu bytes) ---\n",
            modeStr, pageStr, pageSize);

        // Test block sizes from 1x to 64x page size
        for (size_t blockSize = pageSize;
            blockSize <= pageSize * 64;
            blockSize += pageSize)
        {
            // Test allocation counts from 0 to MaxAllocs in 1000-step increments
            for (size_t count = 0; count <= MaxAllocs; count += 1000)
            {
                TimeAllocMemoryWithParams(topDown, blockSize, count, useLargePages);
            }

            // Immediate cleanup after each block size
            for (size_t i = 0; i < MaxAllocs; ++i)
            {
                if (pMem[i])
                {
                    VirtualFree(pMem[i], 0, MEM_RELEASE);
                    pMem[i] = nullptr;
                }
            }
            memset(pMem, 0, sizeof(pMem));
        }
    }

    printf("\nTests completed.\n");
    return 0;
}
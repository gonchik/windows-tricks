REM This command defines how much space the Master File Table should allocate from the volume. It is beneficial to tune in case if many files are stored on the volume.
REM To check the current value the nfutil.exe (or "fsutil fsinfo ntfsinfo X:") can be used.
REM To prevent MFT to run out of space and avoid fragmentation its the value can be changed. The default is 1 (12.5%).
REM I suggest to set it to 2 initially as it doubles the size of the MFT allocation.

fsutil behavior set mftzone 2


REM This command eliminates unnecessary write operations to the "Last Access Time" attribute for frequently used files on the volume.
REM Once changed, the attribute will show only their time of creation. May affect operation of backup softwares that use Remote Storage Service.

fsutil behavior set disablelastaccess 1

REM This command disables short (8.3) filenames. The performance may be noticeable only on volumes with large number of files. Needs to be tested for compatibility with the old software.

fsutil behavior set disable8dot3 1


REM Disabling compression on NTFS drive may decrease CPU usage by removing the need to compress files

fsutil behavior set DisableCompression 1



REM In case the FileServer this change may have a sense
fsutil behavior set memoryusage 2

echo now you can reboot
REM Reboot the server
REM shutdown /r /t 0 /d p:2:4



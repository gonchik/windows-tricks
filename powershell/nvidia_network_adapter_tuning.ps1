# Latency tuning for NVIDIA network adapters
# https://docs.nvidia.com/networking/display/winof2v241/performance+tuning
$key = "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Tcpip\Parameters"
ForceRegKey($key)
Set-ItemProperty -Path $key -Name SackOpts -Type DWORD -Value 0x0 -Force

$key = " HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\AFD\Parameters"
ForceRegKey($key)
Set-ItemProperty -Path $key -Name FastSendDatagramThreshold -Type DWORD -Value 0x0 -Force

$key = "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\Ndis\Parameters"
ForceRegKey($key)
Set-ItemProperty -Path $key -Name RssBaseCpu -Type DWORD -Value 0x0 -Force

# old legacy parameter
# https://learn.microsoft.com/en-us/troubleshoot/windows-server/networking/information-about-tcp-chimney-offload-rss-netdma-feature
# netsh int tcp set global rss=enabled
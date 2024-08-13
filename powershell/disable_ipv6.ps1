# Disable IPv6
$key = "HKLM:\SYSTEM\CurrentControlSet\Services\Tcpip6\Parameters"
ForceRegKey($key)
Set-ItemProperty -Path %key -Name DisabledComponents -Value 0xff -Force
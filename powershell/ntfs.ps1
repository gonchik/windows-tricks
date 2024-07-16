# Let's increase NTFS MFT zone size
# All info there https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-behavior
Invoke-Command -ScriptBlock { fsutil behavior set mftzone 2 }

# Disable last access time on all files
Invoke-Command -ScriptBlock { fsutil behavior set Disablelastaccess 1 }

# Disable 8dot3 filenames
# http://archive.oreilly.com/cs/user/view/cs_msg/95219 (some installers need 8dot3 filenames)
# Warning: Some applications such as incremental backup utilities rely on this update information and do not function correctly without it.

Invoke-Command -ScriptBlock { fsutil behavior set Disable8dot3 1 }

# Disable compression of NTFS
Invoke-Command -ScriptBlock { fsutil behavior set DisableCompression 1 }

Write-Host "Now you can reboot"
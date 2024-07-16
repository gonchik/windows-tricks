REM  Let's increase NTFS MFT zone size
REM All info there https://learn.microsoft.com/en-us/windows-server/administration/windows-commands/fsutil-behavior
fsutil behavior set mftzone 3

REM disable last access time on all files
fsutil behavior set disablelastaccess 1

REM http://archive.oreilly.com/cs/user/view/cs_msg/95219 (some installers need 8dot3 filenames)
REM disable 8dot3 filenames
REM Warning: Some applications such as incremental backup utilities rely on this update information and do not function correctly without it.
fsutil behavior set disable8dot3 1

REM Disable compression of NTFS
fsutil behavior set DisableCompression 1

echo now you can reboot
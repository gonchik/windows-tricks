@echo Stop useless services
powershell "set-service RemoteRegistry -StartupType Disabled -PassThru | Stop-Service -PassThru"
powershell "Set-Service Spooler -StartupType Disabled -PassThru | Stop-Service -PassThru"
powershell "Set-Service edgeupdate -StartupType Disabled -PassThru | Stop-Service -PassThru"
powershell "Set-Service edgeupdatem -StartupType Disabled -PassThru | Stop-Service -PassThru"
powershell "Set-Service wersvc -StartupType Disabled -PassThru | Stop-Service -PassThru"
@echo Remove Defender and Data Archiver components
powershell Uninstall-WindowsFeature -Name Windows-Defender
powershell Uninstall-WindowsFeature -Name System-DataArchiver
powershell Uninstall-WindowsFeature -Name AzureArcSetup
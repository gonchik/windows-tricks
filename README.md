# Windows Tricks
A collection of scripts for making adjustments and improvements to Windows.

## Task 1
Identify possible issue (mitigate with that) and necessary improvements in the `bat`/`ntfs.bat` script.
You don't have all info, as author of that script is on vacation.

The script contains commands that may improve disk and CPU performance on the servers with NTFS volumes that store large number of files.
There are some commands that may cause problems of compatibility with the old software. In addition some commands require reboot.
I've added additional remarks and suggestions within the script to have extended description of what every command does.
It is possible to execute it within the dev environment initially in order to estimate any possible impact.


## Task 2
Someone converted configs into powershell and you need to locate bugs 
and suggest needed enhancements for the `powershell`/`ntfs.ps1` script.

This task contains a PowerShell script that executes the exact commands from the Task 1, hence, all the remarks from ntfs.bat are applied here a well.
Besides, additional checks may be required since Invoke-Command allows scripts to be executed on remote servers.
There are no errors discovered during execution in the test environment, however, I believe that ntfs.bat would be sufficient if approved to run locally only.


## Task 3
The security and Windows team have provided you with a regedit file `regedit`/`general_tweaks.reg` to make enhancements for Windows Server 2022/2019.
Ensure that you backup your registry before applying this file.
Carefully review all parameters before applying the file and add at least 3-4 improvements.
Additionally, provide explanations for each enhancement.
Identify and explain any unnecessary parameters.

By looking at the general_tweaks.reg file I can assume that it has been designed for Windows 10 and developed by 3rd party entity.
Even if it may positively impact performance on Windows desktop OS it doesn't mean it can be fully applied to Windows Servers.
I've checked each registry entry from the file to match the ones on the Windows Server 2019/2022 and the majority of them have no correlation at all.
Nonetheless, there are very few registry entries that may be beneficial for Windows Server OS, although they have to be tested within the test environment.


## Task 4
Your boss has asked you to assess the performance of Windows Server 2022/2019 because Grafana metrics indicate a significant increase in IO latency on the storage system.
There are no new entries in your change logs, and no changes at the virtualization level except for VMware Tools updates.

### Questions:
1. How to investigate the issue using a trace log (based on xperf).
   Hint: [Measuring DPC ISR Time](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/example-15--measuring-dpc-isr-time)

2. How to troubleshoot if vmtoolsd.exe is calling a function and the symbols hub is showing some errors.
   Hints: Check the configurations in the xperf folder and make a pull request adding +1 symbol server that allocates VMware Tools PDB.


## Task 5
Your colleague has asked you to validate policy from [CIS Benchmarks](https://downloads.cisecurity.org/#/) for Windows Server 2022 for your production servers.
You have to describe following details:
- Process of enrollment (dev-test-stage-preprod-prod)
- Policy validation procedure (perftest-sec-test-benchmark-test)
- Report generation (how it will be better to provide)
or provide alternative solution.

CIS Benchmarks are extremely powerfull when it comes to OS security hardening. In case of Windows OS, they provide extensive information on how to configure group policy settings in order to eliminate opportunities for the hackers to take advantage of existing breaches due to non-configured settings or wrong configurations applied. 
In order to implement such configurations and ensure smooth operations of the systems a test environment is required. 
To do so we need to create an OU that will contain a test group of servers that run desired software or/and roles that will exactly replicate the production environment. 
Once it's done we can start creating Group Policy objects that will reflect the settings referenced in CIS Benchmarks.
The next step will be to apply the GPO on the OU that contains group of servers and investigate the impact on performance, stability and usability of the OS and underlying roles/software. 
This process should possibly involve members of different departments who rely on the softwares and server roles within production environment in order to test and verify that anything operates as it's expected. 
The test itself should include various performance, security and stability checks. 
Once the test period is complete and all the parties are satisfied with the results, the hardening policy should be applied to a small group of production servers, using security filters, for example. This will allow to narrow down the impact of the policy in action. 
Further propagation of the policy depends on feedback, performance and reliability reports. 

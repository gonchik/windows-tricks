# Windows Tricks
A collection of scripts for making adjustments and improvements to Windows.

## Task 1
Identify possible issue (mitigate with that) and necessary improvements in the `ntfs.bat` script.

## Task 2
Locate bugs and suggest needed enhancements for the `ntfs.bat` script.

## Task 3
The security and Windows team have provided you with a regedit file to make enhancements for Windows Server 2022/2019.
Ensure that you backup your registry before applying this file.
Carefully review all parameters before applying the file and add at least 3-4 improvements.
Additionally, provide explanations for each enhancement.
Identify and explain any unnecessary parameters.

## Task 4
Your boss has asked you to assess the performance of Windows Server 2022/2019 because Grafana metrics indicate a significant increase in IO latency on the storage system.
There are no new entries in your change logs, and no changes at the virtualization level except for VMware Tools updates.

### Questions:
1. How to investigate the issue using a trace log (based on xperf).
   Hint: [Measuring DPC ISR Time](https://learn.microsoft.com/en-us/windows-hardware/drivers/devtest/example-15--measuring-dpc-isr-time)

2. How to troubleshoot if vmtoolsd.exe is calling a function and the symbols hub is showing some errors.
   Hints: Check the configurations in the xperf folder and make a pull request adding +1 symbol server that allocates VMware Tools PDB.
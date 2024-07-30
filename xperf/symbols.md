# List of Symbol Servers

| Name                    | Location                                                                                                                                                                                                                                     | Comment                                                                                |
|-------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------|
| AMD PE only             | [https://download.amd.com/dir/bin](https://download.amd.com/dir/bin)                                                                                                                                                                         |                                                                                        |
| AutoDesk                | [http://symbols.autodesk.com/](http://symbols.autodesk.com/)                                                                                                                                                                                 |                                                                                        |
| BTRFS for Windows       | [http://symbols.burntcomma.com](http://symbols.burntcomma.com)                                                                                                                                                                               |                                                                                        |
| BOINC                   | [https://boinc.berkeley.edu/symstore/](https://boinc.berkeley.edu/symstore/)                                                                                                                                                                 |                                                                                        |
| BOINC Rosetta           | [http://boinc.bakerlab.org/rosetta/symstore/](http://boinc.bakerlab.org/rosetta/symstore/)                                                                                                                                                   |                                                                                        |
| Citrix                  | [https://ctxsym.citrix.com/symbols](https://ctxsym.citrix.com/symbols)                                                                                                                                                                       |                                                                                        |
| Dolphin                 | [https://symbols.dolphin-emu.org/](https://symbols.dolphin-emu.org/)                                                                                                                                                                         |                                                                                        |
| ElectronJS              | [https://symbols.electronjs.org/](https://symbols.electronjs.org/)                                                                                                                                                                           |                                                                                        |
| Encodo                  | [https://encodo.artifacts.visualstudio.com/_apis/Symbol/symsrv/](https://encodo.artifacts.visualstudio.com/_apis/Symbol/symsrv/)                                                                                                             |                                                                                        |
| Google Chrome           | [https://chromium-browser-symsrv.commondatastorage.googleapis.com](https://chromium-browser-symsrv.commondatastorage.googleapis.com)                                                                                                         | Helpful to double check services of Google Chrome like updater which works during news |
| Intel PE only           | [https://software.intel.com/sites/downloads/symbols](https://software.intel.com/sites/downloads/symbols)                                                                                                                                     |                                                                                        |
| LibreOffice development | [https://dev-builds.libreoffice.org/windows-debug/symbols](https://dev-builds.libreoffice.org/windows-debug/symbols) <br> [https://dev-builds.libreoffice.org/win32-debug/symbols/](https://dev-builds.libreoffice.org/win32-debug/symbols/) | This server caches many unknown services from Windows                                  |
| Mozilla                 | [https://symbols.mozilla.org/](https://symbols.mozilla.org/)                                                                                                                                                                                 | Caching many open-source tools                                                         |
| Nvidia                  | [https://driver-symbols.nvidia.com/](https://driver-symbols.nvidia.com/)                                                                                                                                                                     |                                                                                        |
| Nuget (Portable PDBs)   | [https://symbols.nuget.org/download/symbols](https://symbols.nuget.org/download/symbols)                                                                                                                                                     |                                                                                        |
| Open Fabrics            | [https://www.openfabrics.org/downloads/Windows/latest/SymStor/](https://www.openfabrics.org/downloads/Windows/latest/SymStor/)                                                                                                               |                                                                                        |
| PyWin                   | [http://pythonsymbols.sdcline.com/symbols](http://pythonsymbols.sdcline.com/symbols)                                                                                                                                                         | Classic Python symbols                                                                 |
| Random ASCII            | [https://randomascii-symbols.commondatastorage.googleapis.com/](https://randomascii-symbols.commondatastorage.googleapis.com/)                                                                                                               |                                                                                        |
| Rhino3D                 | [http://s3.symbols.rhino3d.com/symbols/dujour/](http://s3.symbols.rhino3d.com/symbols/dujour/)                                                                                                                                               |                                                                                        |
| Safari Windows Symbols  | [http://developer.apple.com/internet/safari/windows_symbols](http://developer.apple.com/internet/safari/windows_symbols)                                                                                                                     |                                                                                        |
| SymbolSource MyGet      | [http://srv.symbolsource.org/pdb/MyGet](http://srv.symbolsource.org/pdb/MyGet)                                                                                                                                                               |                                                                                        |
| SymbolSource Public     | [http://srv.symbolsource.org/pdb/Public](http://srv.symbolsource.org/pdb/Public)                                                                                                                                                             |                                                                                        |
| SymWeb                  | [https://symweb.corp.microsoft.com/](https://symweb.corp.microsoft.com/)                                                                                                                                                                     |                                                                                        |
| Unity                   | [http://symbolserver.unity3d.com](http://symbolserver.unity3d.com)                                                                                                                                                                           | Not used                                                                               |
| Windows and .net        | [https://referencesource.microsoft.com/symbols](https://referencesource.microsoft.com/symbols) <br> [http://msdl.microsoft.com/download/symbols](http://msdl.microsoft.com/download/symbols)                                                 | Classic Windows and .net                                                               |

formatted for xperf, WPT and WinDbg

```plaintext
srv*C:\gon4ik\symbols*http://developer.apple.com/internet/safari/windows_symbols
srv*C:\gon4ik\symbols*http://msdl.microsoft.com/download/symbols
srv*C:\gon4ik\symbols*http://pythonsymbols.sdcline.com/symbols
srv*C:\gon4ik\symbols*http://s3.symbols.rhino3d.com/symbols/dujour/
srv*C:\gon4ik\symbols*http://srv.symbolsource.org/pdb/MyGet
srv*C:\gon4ik\symbols*http://srv.symbolsource.org/pdb/Public
srv*C:\gon4ik\symbols*http://symbolserver.unity3d.com
srv*C:\gon4ik\symbols*http://symbols.autodesk.com
srv*C:\gon4ik\symbols*http://symbols.burntcomma.com
srv*C:\gon4ik\symbols*https://chromium-browser-symsrv.commondatastorage.googleapis.com
srv*C:\gon4ik\symbols*https://ctxsym.citrix.com/symbols
srv*C:\gon4ik\symbols*https://dev-builds.libreoffice.org/win32-debug/symbols
srv*C:\gon4ik\symbols*https://dev-builds.libreoffice.org/windows-debug/symbols
srv*C:\gon4ik\symbols*https://download.amd.com/dir/bin
srv*C:\gon4ik\symbols*https://download.amd.com/dir/bin_2018
srv*C:\gon4ik\symbols*https://driver-symbols.nvidia.com
srv*C:\gon4ik\symbols*https://encodo.artifacts.visualstudio.com/_apis/Symbol/symsrv/
srv*C:\gon4ik\symbols*https://referencesource.microsoft.com/symbols
srv*C:\gon4ik\symbols*https://software.intel.com/sites/downloads/symbols
srv*C:\gon4ik\symbols*https://symbols.electronjs.org
srv*C:\gon4ik\symbols*https://symbols.mozilla.org
srv*C:\gon4ik\symbols*https://symbols.nuget.org/download/symbols
srv*C:\gon4ik\symbols*https://randomascii-symbols.commondatastorage.googleapis.com/
srv*C:\gon4ik\symbols*https://boinc.berkeley.edu/symstore/
srv*C:\gon4ik\symbols*http://boinc.bakerlab.org/rosetta/symstore/
srv*C:\gon4ik\symbols*https://symbols.dolphin-emu.org/
srv*C:\gon4ik\symbols*https://symweb.corp.microsoft.com/
srv*C:\gon4ik\symbols*https://www.openfabrics.org/downloads/Windows/latest/SymStor/
```
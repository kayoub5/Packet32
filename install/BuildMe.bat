@echo off

msbuild MakeAll.sln /t:Build	/p:Configuration="Release"			/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No AirPcap"		/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No NetMon"		/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release NT4"			/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release LOG_TO_FILE"		/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No NetMon LOG_TO_FILE" /p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release NT4 LOG_TO_FILE"	/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug"			/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug No AirPcap"		/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug No NetMon"		/p:Platform="Win32"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug NT4"			/p:Platform="Win32"

msbuild MakeAll.sln /t:Build	/p:Configuration="Release"			/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No AirPcap"		/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No NetMon"		/p:Platform="x64"
rem msbuild MakeAll.sln /t:Build	/p:Configuration="Release NT4"			/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release LOG_TO_FILE"		/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Release No NetMon LOG_TO_FILE" /p:Platform="x64"
rem msbuild MakeAll.sln /t:Build	/p:Configuration="Release NT4 LOG_TO_FILE"	/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug"			/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug No AirPcap"		/p:Platform="x64"
msbuild MakeAll.sln /t:Build	/p:Configuration="Debug No NetMon"		/p:Platform="x64"
rem msbuild MakeAll.sln /t:Build	/p:Configuration="Debug NT4"			/p:Platform="x64"
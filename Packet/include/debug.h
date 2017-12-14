/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __PACKET_DEBUG_393073863432093179878957
#define __PACKET_DEBUG_393073863432093179878957

#if defined(_DBG) || defined(_DEBUG_TO_FILE)

#include <stdio.h>
#include <windows.h>

#include <tchar.h>

#pragma warning(push)
#pragma warning(disable : 4127)

static VOID OutputDebugStringV(LPCTSTR Format, ...)
{
	FILE *f;
	SYSTEMTIME LocalTime;
	va_list Marker;
	DWORD dwThreadId;
	int loops = 0;
	DWORD dwLastError = GetLastError();

	dwThreadId = GetCurrentThreadId();

	va_start(Marker, Format); /* Initialize variable arguments. */

	GetLocalTime(&LocalTime);

	do
	{

#ifdef _CONSOLE
		if (_tfopen_s(&f, _T("C:\\Program Files\\Npcap\\NPFInstall.log"), _T("a,ccs=UTF-8")) == 0)
#else
		if (_tfopen_s(&f, _T("C:\\Program Files\\Npcap\\Packet.log"), _T("a,ccs=UTF-8")) == 0)
#endif
			break;

		Sleep(0);
		loops++;

		if (loops > 10)
		{
			SetLastError(dwLastError);
			return;
		}
	}
	while(1);

	_ftprintf(f, _T("[%.08X] %.04u-%.02u-%.02u %.02u:%02u:%02u "),
			dwThreadId,
			LocalTime.wYear,
			LocalTime.wMonth,
			LocalTime.wDay,
			LocalTime.wHour,
			LocalTime.wMinute,
			LocalTime.wSecond);
	_vftprintf(f, Format, Marker);

	fclose(f);


	SetLastError(dwLastError);
}

#pragma warning(pop)

#elif defined (_DBG)
// XXX - remove me!
#include <strsafe.h>

static VOID OutputDebugStringV(LPCTSTR Format, ...)
{
	va_list Marker;
	TCHAR string[1024];
	DWORD dwLastError = GetLastError();

	va_start(Marker, Format); /* Initialize variable arguments. */

	StringCchVPrintf(string, sizeof(string), Format, Marker);

	OutputDebugString(string);

	va_end(Marker);

	SetLastError(dwLastError);
}
#endif


#if defined(_DBG) || defined(_DEBUG_TO_FILE)

#define TRACE_ENTER()									OutputDebugStringV(_T("--> ") _T(__FUNCTION__) _T("\n"))
#define TRACE_EXIT()									OutputDebugStringV(_T("<-- ") _T(__FUNCTION__) _T("\n"))
#define TRACE_PRINT(_x)									OutputDebugStringV(_T("    ") _T(_x) _T("\n"))
#define TRACE_PRINT1(_x, _p1)							OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1)
#define TRACE_PRINT2(_x, _p1, _p2)						OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1, _p2)
#define TRACE_PRINT3(_x, _p1, _p2, _p3)					OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1, _p2, _p3)
#define TRACE_PRINT4(_x, _p1, _p2, _p3, _p4)			OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1, _p2, _p3, _p4)
#define TRACE_PRINT5(_x, _p1, _p2, _p3, _p4, _p5)		OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1, _p2, _p3, _p4, _p5)
#define TRACE_PRINT6(_x, _p1, _p2, _p3, _p4, _p5, _p6)	OutputDebugStringV(_T("    ") _T(_x) _T("\n"), _p1, _p2, _p3, _p4, _p5, _p6)

static __forceinline void TRACE_PRINT_OS_INFO()
{
	HKEY	hKey;
	CHAR buffer[1024];
	DWORD size = sizeof(buffer);
	DWORD type;
	DWORD dwLastError;

	dwLastError = GetLastError();

	TRACE_PRINT("********************* OS info.*********************");
	buffer[size-1] = 0;
	size = sizeof(buffer);
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment"), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
	{
		if (RegQueryValueEx(hKey, _T("PROCESSOR_ARCHITECTURE"), 0, &type, (LPBYTE)buffer, &size) == ERROR_SUCCESS && type == REG_SZ)
		{
			OutputDebugStringV(_T("Architecture = %hs\n"), buffer);
		}
		else
		{
			OutputDebugStringV(_T("Architecture = <UNKNOWN>\n"));
		}

		RegCloseKey(hKey);
	}
	else
	{
		OutputDebugStringV(_T("Architecture = <UNKNOWN>\n"));
	}

	buffer[size-1] = 0;
	size = sizeof(buffer);

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
	{
		if (RegQueryValueEx(hKey, _T("CurrentVersion"), 0, &type,  (LPBYTE)buffer, &size) == ERROR_SUCCESS && type == REG_SZ)
		{
			OutputDebugStringV(_T("Windows version = %hs\n"), buffer);
		}
		else
		{
			OutputDebugStringV(_T("Windows version = <UNKNOWN>\n"));
		}

		RegCloseKey(hKey);
	}
	else
	{
		OutputDebugStringV(_T("Windows version = <UNKNOWN>\n"));
	}

	buffer[size-1] = 0;
	size = sizeof(buffer);
	if(	RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion"), 0, KEY_READ, &hKey) == ERROR_SUCCESS)
	{
		if (RegQueryValueEx(hKey, _T("CurrentType"), 0, &type,  (LPBYTE)buffer, &size) == ERROR_SUCCESS && type == REG_SZ)
		{
			OutputDebugStringV(_T("Windows CurrentType = %hs\n"), buffer);
		}
		else
		{
			OutputDebugStringV(_T("Windows CurrentType = <UNKNOWN>\n"));
		}

		RegCloseKey(hKey);
	}
	else
	{
		OutputDebugStringV(_T("Windows CurrentType = <UNKNOWN>\n"));
	}

	OutputDebugStringV(_T("*************************************************** \n"));

	SetLastError(dwLastError);
}
#else

#define TRACE_ENTER()
#define TRACE_EXIT()
#define TRACE_PRINT(_x)
#define TRACE_PRINT1(_x, _p1)
#define TRACE_PRINT2(_x, _p1, _p2)
#define TRACE_PRINT3(_x, _p1, _p2, _p3)
#define TRACE_PRINT4(_x, _p1, _p2, _p3, _p4)
#define TRACE_PRINT5(_x, _p1, _p2, _p3, _p4, _p5)
#define TRACE_PRINT6(_x, _p1, _p2, _p3, _p4, _p5, _p6)
#define TRACE_PRINT_WIDECHAR(_x)
#define TRACE_PRINT_OS_INFO()

#endif



#endif //__PACKET_DEBUG_393073863432093179878957

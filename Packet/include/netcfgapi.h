/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 2001.
//
//  File:   	N E T C F G A P I . H
//
//  Contents:   Functions Prototypes
//
//  Notes:  	
//
//  Author: 	Alok Sinha    15-May-01
//
//----------------------------------------------------------------------------

#ifndef _NETCFGAPI_H_INCLUDED

#define _NETCFGAPI_H_INCLUDED

#pragma warning(disable: 4996)
#pragma warning(disable: 4311 4312)
#include <iostream>
#include <tchar.h>


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wchar.h>
#include <netcfgx.h>
#include <netcfgn.h>
#include <setupapi.h>
#include <devguid.h>
#include <objbase.h>
#include <atlbase.h>

#define LOCK_TIME_OUT     5000

HRESULT HrGetINetCfg(IN BOOL fGetWriteLock, IN LPCTSTR lpszAppName, OUT INetCfg** ppnc, OUT LPTSTR* lpszLockedBy);

HRESULT HrReleaseINetCfg(INetCfg* pnc, BOOL fHasWriteLock);

HRESULT HrInstallNetComponent(IN INetCfg* pnc, IN const GUID* pguildClass, IN LPCTSTR lpszInfFullPath);

HRESULT HrInstallComponent(IN INetCfg* pnc, IN LPCTSTR szComponentId, IN const GUID* pguidClass);

HRESULT HrUninstallNetComponent(IN INetCfg* pnc, IN LPCTSTR szComponentId);

VOID ReleaseRef(IUnknown* punk);

BOOL RestartAllBindings(INetCfg *netcfg, PCWSTR szComponentId);

BOOL ConnectToNetCfg(PCWSTR lpszPnpID, LPTSTR lpszAppName);

#endif

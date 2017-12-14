/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#include <windows.h>
#include <windowsx.h>
#include <vector>
using namespace std;

typedef std::basic_string<TCHAR> tstring;

#ifdef UNICODE
	#define RPC_TSTR RPC_WSTR
#else
	#define RPC_TSTR RPC_CSTR
#endif

tstring OperationMode2String(ULONG OperationMode);
ULONG String2OperationMode(tstring strOperationMode);

tstring PhyType2String(ULONG PhyType);
ULONG String2PhyType(tstring strPhyType);

tstring NdisStatus2Message(DWORD dwStatus);

tstring printArray(vector<tstring> nstr);

tstring itos(int i);

tstring executeCommand(TCHAR* cmd);

void initAdapterList();

tstring getGuidFromAdapterName(tstring strAdapterName);
tstring getAdapterNameFromGuid(tstring strGuid);

BOOL makeOIDRequest(tstring strAdapterGUID, ULONG iOid, BOOL bSet, PVOID pData, ULONG ulDataSize);

BOOL GetCurrentOperationMode(tstring strGUID, tstring &strMode);
BOOL SetCurrentOperationMode(tstring strGUID, tstring strMode);

BOOL GetOperationModeCapability(tstring strGUID, tstring &strModes);
BOOL IsMonitorModeSupported(tstring strGUID);

BOOL GetCurrentChannel(tstring strGUID, ULONG &ulChannel);
BOOL SetCurrentChannel(tstring strGUID, ULONG ulChannel);

BOOL GetCurrentFrequency(tstring strGUID, ULONG &ulFrequency);
BOOL SetCurrentFrequency(tstring strGUID, ULONG ulFrequency);

BOOL GetSupportedPhyTypes(tstring strGUID, vector<tstring> &strPhyTypes);
BOOL GetDesiredPhyList(tstring strGUID, vector<tstring> &nstrPhyList);
BOOL GetCurrentPhyID(tstring strGUID, tstring &strPhyID);
BOOL SetCurrentPhyID(tstring strGUID, tstring strPhyID);

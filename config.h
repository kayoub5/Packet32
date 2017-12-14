//#define WSOCK_TRACE
#define HAVE_IPHELPER_API

// Disable some overeager MSVC level 4 warnings.
// XXX - move almost all #pragma warning() to here
#pragma warning(disable: 4996) /* _CRT_SECURE_NO_WARNINGS, _WINSOCK_DEPRECATED_NO_WARNINGS and Co. */

// Stuff to link with.
#ifdef WIN_NT_DRIVER
//#pragma comment (lib,"wdmsec")       /* Windows Driver Model Device Secure */
//#pragma comment (lib,"ndis")         /* Network Driver Interface Specification */
//#pragma comment (lib,"Ntstrsafe")    /* Kernel-Mode Safe String Functions */
//#pragma comment (lib,"fwpkclnt")     /* Windows Filtering Platform API */
//#pragma comment (lib,"uuid")         /* Universally Unique Identifiers */
//#pragma comment (lib,"netio")        /* Network Programming Interface */
#else
#ifdef WSOCK_TRACE /* https://github.com/gvanem/wsock-trace */
  #ifdef _WIN64
  #pragma comment (lib,"wsock_trace_x64")
  #else
  #pragma comment (lib,"wsock_trace")
  #endif
#else
  #pragma comment (lib,"ws2_32")
#endif

#ifdef HAVE_IPHELPER_API
#pragma comment (lib,"iphlpapi")         /* IP Helper API */
#endif

#pragma comment (lib,"setupapi")         /* Setup API */
#endif
/*
* The Setup API provides a set of functions that a setup application calls to perform
* installation operations where applicable.
* These setup functions are available to develop a setup application.
*/
#pragma comment (lib,"version")           /* version */
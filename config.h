
// Disable some overeager MSVC level 4 warnings.
#pragma warning(disable: 4996) /* _CRT_SECURE_NO_WARNINGS, _WINSOCK_DEPRECATED_NO_WARNINGS and Co. */

//#define HAVE_AIRPCAP_API

// Stuff to link with.
#ifdef WIN_NT_DRIVER
//#pragma comment (lib,"wdmsec")           /* winsock 2 */
//#pragma comment (lib,"ndis")         /* IP Helper API */
//#pragma comment (lib,"Ntstrsafe")         /* Setup API */
//#pragma comment (lib,"fwpkclnt")           /* winsock 2 */
//#pragma comment (lib,"uuid")         /* IP Helper API */
//#pragma comment (lib,"netio")         /* Setup API */
#else
#pragma comment (lib,"ws2_32")           /* winsock 2 */
#pragma comment (lib,"iphlpapi")         /* IP Helper API */
#pragma comment (lib,"setupapi")         /* Setup API */
#endif
/*
* The Setup API provides a set of functions that a setup application calls to perform
* installation operations where applicable.
* These setup functions are available to develop a setup application.
*/
#pragma comment (lib,"version")           /* version */
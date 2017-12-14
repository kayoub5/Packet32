/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#ifndef __memory_t
#define __memory_t

#define		uint8	UCHAR
#define		int8	CHAR
#define		uint16	USHORT
#define		int16	SHORT
#define		uint32	ULONG
#define		int32	LONG
#define		uint64	ULONGLONG
#define		int64	LONGLONG

/*memory type*/
typedef struct __MEM_TYPE
{
	uint8* buffer;
	uint32 size;
}  MEM_TYPE, * PMEM_TYPE;

#define LONG_AT(base,offset) (*(int32*)((uint8*)base+(uint32)offset))

#define ULONG_AT(base,offset) (*(uint32*)((uint8*)base+(uint32)offset))

#define SHORT_AT(base,offset) (*(int16*)((uint8*)base+(uint32)offset))

#define USHORT_AT(base,offset) (*(uint16*)((uint8*)base+(uint32)offset))

__inline int32 SW_LONG_AT(void* b, uint32 c)
{
	return	((int32)*((uint8 *)b + c) << 24 | (int32)*((uint8 *)b + c + 1) << 16 | (int32)*((uint8 *)b + c + 2) << 8 | (int32)*((uint8 *)b + c + 3) << 0);
}


__inline uint32 SW_ULONG_AT(void* b, uint32 c)
{
	return	((uint32)*((uint8 *)b + c) << 24 | (uint32)*((uint8 *)b + c + 1) << 16 | (uint32)*((uint8 *)b + c + 2) << 8 | (uint32)*((uint8 *)b + c + 3) << 0);
}

__inline int16 SW_SHORT_AT(void* b, uint32 os)
{
	return ((int16)((int16)*((uint8 *)b + os + 0) << 8 | (int16)*((uint8 *)b + os + 1) << 0));
}

__inline uint16 SW_USHORT_AT(void* b, uint32 os)
{
	return ((uint16)((uint16)*((uint8 *)b + os + 0) << 8 | (uint16)*((uint8 *)b + os + 1) << 0));
}

__inline VOID SW_ULONG_ASSIGN(void* dst, uint32 src)
{
	*((uint8 *)dst + 0) = *((uint8 *)&src + 3);
	*((uint8 *)dst + 1) = *((uint8 *)&src + 2);
	*((uint8 *)dst + 2) = *((uint8 *)&src + 1);
	*((uint8 *)dst + 3) = *((uint8 *)&src + 0);
}

#ifdef WIN_NT_DRIVER

#define ALLOCATE_MEMORY(dest,type,amount) \
	  (dest)=ExAllocatePoolWithTag(NonPagedPool,sizeof(type)*(amount), '0TWA');
#define ALLOCATE_ZERO_MEMORY(dest,type,amount) \
	{ \
		(dest)=ExAllocatePoolWithTag(NonPagedPool,sizeof(type)*(amount), '1TWA'); \
		if ((dest)!=NULL) \
			RtlZeroMemory((dest),sizeof(type)*(amount)); \
	}	

#define FREE_MEMORY(dest) ExFreePool(dest);
#define ZERO_MEMORY(dest,amount) RtlZeroMemory(dest,amount);
#define COPY_MEMORY(dest,src,amount) RtlCopyMemory(dest,src,amount);

#else

#define ALLOCATE_MEMORY(dest,type,amount) \
	  (dest)=(type*)GlobalAlloc(GPTR, sizeof(type)*(amount));
#define ALLOCATE_ZERO_MEMORY(dest,type,amount) \
	  (dest)=(type*)GlobalAlloc(GPTR, sizeof(type)*(amount));

#define FREE_MEMORY(dest) GlobalFree(dest);
#define ZERO_MEMORY(dest,amount) RtlZeroMemory(dest,amount);
#define COPY_MEMORY(dest,src,amount) RtlCopyMemory(dest,src,amount);


#endif /*WIN_NT_DRIVER*/



#endif 


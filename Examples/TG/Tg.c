/*
 * Copyright (c) 1999 - 2003
 * NetGroup, Politecnico di Torino (Italy)
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright 
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright 
 * notice, this list of conditions and the following disclaimer in the 
 * documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Politecnico di Torino nor the names of its 
 * contributors may be used to endorse or promote products derived from 
 * this software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


#include <stdio.h>
#include <conio.h>
#include <time.h>

#include "..\..\Include\packet32.h"


#define Max_Num_Adapter 10

// Prototypes

void PrintPackets(LPPACKET lpPacket);

char        AdapterList[Max_Num_Adapter][8192];



int main(int argc, char **argv)
{
	
	char packetbuff[5000];
	
	// define a pointer to a ADAPTER structure
	
	LPADAPTER  lpAdapter = 0;
	
	// define a pointer to a PACKET structure
	
	LPPACKET   lpPacket;
	
	int        i,npacks,Snaplen;
	DWORD      dwErrorCode;
	
	DWORD dwVersion;
	DWORD dwWindowsMajorVersion;
	
	//unicode strings (winnt)
	WCHAR		AdapterName[8192]; // string that contains a list of the network adapters
	WCHAR		*temp,*temp1;
	
	//ascii strings (win95)
	char		AdapterNamea[8192]; // string that contains a list of the network adapters
	char		*tempa,*temp1a;
	
	int			AdapterNum=0,Open;
	ULONG		AdapterLength;
	
	float	cpu_time;
	
	printf("Traffic Generator v 0.9999\nCopyright 1999 Loris Degioanni (loris@netgroup-serv.polito.it)");
	printf("\nSends a set of packets to the network.");
	
	if (argc == 1){
		printf("\n\n Usage: tg [-i adapter] -n npacks -s size");
		printf("\n size is between 60 and 1514\n\n");
		return -1;
	}
	
	
	AdapterNamea[0]=0;
	
	//get the command line parameters
	for(i=1;i<argc;i+=2){
		
		switch (argv[i] [1])
		{
			
		case 'i':
			sscanf(argv[i+1],"%s",AdapterNamea);
			break;
			
		case 'n':
			sscanf(argv[i+1],"%d",&npacks);
			break;
			
		case 's':
			sscanf(argv[i+1],"%d",&Snaplen);
			break;
			
		}
		
	}
	
	
	
	if(AdapterNamea[0]==0){
		
		//
		// Obtain the name of the adapters installed on this machine		
		//
		printf("Adapters installed:\n");
		i=0;
		
		// the data returned by PacketGetAdapterNames is different in Win95 and in WinNT.
		// We have to check the os on which we are running
		dwVersion=GetVersion();
		dwWindowsMajorVersion =  (DWORD)(LOBYTE(LOWORD(dwVersion)));
		if (!(dwVersion >= 0x80000000 && dwWindowsMajorVersion >= 4))
		{  // Windows NT
			AdapterLength = sizeof(AdapterName);

			if(PacketGetAdapterNames(AdapterName,&AdapterLength)==FALSE){
				printf("Unable to retrieve the list of the adapters!\n");
				return -1;
			}

			temp=AdapterName;
			temp1=AdapterName;
			while ((*temp!='\0')||(*(temp-1)!='\0'))
			{
				if (*temp=='\0') 
				{
					memcpy(AdapterList[i],temp1,(temp-temp1)*2);
					temp1=temp+1;
					i++;
				}
				
				temp++;
			}
			
			AdapterNum=i;
			for (i=0;i<AdapterNum;i++)
				wprintf(L"\n%d- %s\n",i+1,AdapterList[i]);
			printf("\n");
			
		}
		
		else	//windows 95
		{
			AdapterLength = sizeof(AdapterNamea);

			if(PacketGetAdapterNames(AdapterNamea,&AdapterLength)==FALSE){
				printf("Unable to retrieve the list of the adapters!\n");
				return -1;
			}
			tempa=AdapterNamea;
			temp1a=AdapterNamea;
			
			while ((*tempa!='\0')||(*(tempa-1)!='\0'))
			{
				if (*tempa=='\0') 
				{
					memcpy(AdapterList[i],temp1a,tempa-temp1a);
					temp1a=tempa+1;
					i++;
				}
				tempa++;
			}
			
			AdapterNum=i;
			for (i=0;i<AdapterNum;i++)
				printf("\n%d- %s\n",i+1,AdapterList[i]);
			printf("\n");
			
		}
		
		do 
		{
			printf("Select the number of the adapter to open : ");scanf("%d",&Open);
			if (Open>AdapterNum) printf("\nThe number must be smaller than %d",AdapterNum); 
		} while (Open>AdapterNum);
		
		
		
		
		lpAdapter =   PacketOpenAdapter(AdapterList[Open-1]);
		
		if (!lpAdapter || (lpAdapter->hFile == INVALID_HANDLE_VALUE))
		{
			dwErrorCode=GetLastError();
			printf("Unable to open the driver, Error Code : %lx\n",dwErrorCode); 
			
			return(-1);
		}	
		
	}
	else{
		
		lpAdapter =  PacketOpenAdapter(AdapterNamea);
		
		if (!lpAdapter || (lpAdapter->hFile == INVALID_HANDLE_VALUE))
		{
			dwErrorCode=GetLastError();
			printf("Unable to open the driver, Error Code : %lx\n",dwErrorCode); 
			
			return(-1);
		}
		
	}
	
	if((lpPacket = PacketAllocatePacket())==NULL){
		printf("\nError:failed to allocate the LPPACKET structure.");
		return (-1);
	}
	
	packetbuff[0]=1;
	packetbuff[1]=1;
	packetbuff[2]=1;
	packetbuff[3]=1;
	packetbuff[4]=1;
	packetbuff[5]=1;
	
	packetbuff[6]=2;
	packetbuff[7]=2;
	packetbuff[8]=2;
	packetbuff[9]=2;
	packetbuff[10]=2;
	packetbuff[11]=2;
	
	for(i=12;i<1514;i++){
		packetbuff[i]=i%256;
	}
	
	PacketInitPacket(lpPacket,packetbuff,Snaplen);
	// capture the packet
	
	
	if(PacketSetNumWrites(lpAdapter,npacks)==FALSE){
		printf("warning: Unable to send more than one packet in a single write!\n");
	}
	
	printf("\n\nGenerating %d packets...",npacks);
	
	cpu_time = clock ();
	
	if(PacketSendPacket(lpAdapter,lpPacket,TRUE)==FALSE){
		printf("Error sending the packets!\n");
		return -1;
	}
	
	cpu_time = (clock() - cpu_time)/CLK_TCK;
	
	printf ("\n\nElapsed time: %5.3f\n", cpu_time);
	printf ("\nTotal packets generated = %d", npacks);
	printf ("\nTotal bytes generated = %d", (Snaplen+24)*npacks);
	printf ("\nTotal bits generated = %d", (Snaplen+24)*npacks*8);
	printf ("\nAverage packets per second = %d", (int)((double)npacks/cpu_time));
	printf ("\nAverage bytes per second = %d", (int)((double)((Snaplen+24)*npacks)/cpu_time));
	printf ("\nAverage bits per second = %d", (int)((double)((Snaplen+24)*npacks*8)/cpu_time));
	printf ("\n");
	
	PacketFreePacket(lpPacket);
	
	// close the adapter and exit
	
	PacketCloseAdapter(lpAdapter);
	return (0);
}

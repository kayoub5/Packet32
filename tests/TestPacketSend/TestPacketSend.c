/**
 * Packet32 has no copyright assigned and is placed in the Public Domain.
 * No warranty is given; refer to the files LICENSE-WTFPL, COPYING.Npcap and
 * COPYING.WinPcap within this package.
 */

#include <stdio.h>
#include <conio.h>
#include <time.h>

#include "Packet32.h"


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

//ascii strings
char		AdapterName[8192]; // string that contains a list of the network adapters
char		*temp,*temp1;

int			AdapterNum=0,Open;
ULONG		AdapterLength;

float	cpu_time;

	printf("Traffic Generator v 0.9999\nCopyright 1999 Loris Degioanni (loris@netgroup-serv.polito.it)");
	printf("\nSends a set of packets to the network using packet.dll API.\n");

	if (argc == 1){
		printf("\n\n Usage: TestpacketSend [-i adapter] -n npacks -s size");
		printf("\n size is between 60 and 1514\n\n");
		return -1;
	}


	AdapterName[0]=0;

	//get the command line parameters
	for(i=1;i<argc;i+=2){

		switch (argv[i] [1])
		{

		case 'i':
			sscanf_s(argv[i+1],"%s",AdapterName);
			break;

		case 'n':
			sscanf_s(argv[i+1],"%d",&npacks);
			break;

		case 's':
			sscanf_s(argv[i+1],"%d",&Snaplen);
			break;

		}

	}



	if(AdapterName[0]==0){

		//
		// Obtain the name of the adapters installed on this machine
		//
		printf("Adapters installed:\n");
		i=0;

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
				memcpy(AdapterList[i],temp1,temp-temp1);
				temp1=temp+1;
				i++;
			}
			temp++;
		}

		AdapterNum=i;
		for (i=0;i<AdapterNum;i++)
			printf("\n%d- %s\n",i+1,AdapterList[i]);
		printf("\n");

		do
		{
			printf("Select the number of the adapter to open : ");scanf_s("%d",&Open);
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

		lpAdapter =  PacketOpenAdapter(AdapterName);

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
		packetbuff[i]= (char)i;
	}

	PacketInitPacket(lpPacket,packetbuff,Snaplen);
	// capture the packet


	if(PacketSetNumWrites(lpAdapter,npacks)==FALSE){
		printf("warning: Unable to send more than one packet in a single write!\n");
	}

	printf("\n\nGenerating %d packets...",npacks);

	cpu_time = (float)clock ();

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

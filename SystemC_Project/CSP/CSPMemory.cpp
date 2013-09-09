#include "CSPMemory.h"              /* Line 2 */
#include <stdio.h>

void CSPMemory::prc_CSPMemory(){ /* Line 3 */
	sc_uint<8> MEM_Data[256]={
		0xBA,0xBB,0x22,0xC1,0xB8,0x50,0xB8,0x30,0xC2,0xC0,0x12,0xC3,0xB5,0xBC,0xBF,0xAE
	};	
	//FILE *stream=fopen("Init_MEM.txt","r");
	if(Rst)
		Memory_out=0;
	else if (MEM_Read)
	{
		//fseek( stream, MEM_Address.read()<<1, SEEK_SET);
		Memory_out=MEM_Data[MEM_Address.read()];
		//Memory_out=CSPMemory_Data;
	}
}

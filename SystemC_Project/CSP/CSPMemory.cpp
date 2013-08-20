#include "CSPMemory.h"              /* Line 2 */
#include <stdio.h>

void CSPMemory::prc_CSPMemory(){ /* Line 3 */
	sc_uint<8> CSPMemory_Data;
	sc_uint<8> MEM_Data[256]={
		0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07
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

#include "CSPMemory.h"              /* Line 2 */
#include <stdio.h>

void CSPMemory::prc_CSPMemory(){ /* Line 3 */
	sc_uint<8> CSPMemory_Data;
	sc_uint<8> MEM_Data[2^8-1]={
		
	};
	//FILE *stream=fopen("Init_MEM.txt","r");
	if(Rst)
		CSPMemory_Data=0;
	else if (MEM_Read)
	{
		//fseek( stream, MEM_Address.read()<<1, SEEK_SET);
		CSPMemory_Data=MEM_Data[MEM_Address.read()];
		Memory_out=CSPMemory_Data;
	}
}

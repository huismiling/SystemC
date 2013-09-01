#include "CSPControl.h"              /* Line 2 */

void CSPControl::prc_CSPControl1(){ /* Line 3 */
	if(Rst)
	{
		W="0001";
	}
	else
	{
		if(!Clk_en & !S_IS)
		{
			W=(W.range(2,0),W[3]);
		}
	}
}

void CSPControl::prc_CSPControl2(){ 
	if(Rst)
	{
		i="0x00010400";
		S_IS="1";
		Clk_en="0";
	}
	else
	{
		if(S_IS)
		{
			switch(Instruction.read())
			{
				case 0xE0:
					S_IS="0";
					i="0x0000EC00";
					break;
				case 0xE1:
					i="0x00010404";
					break;
			}
		}
	}
}
#include "CSPMACTimer.h"              /* Line 2 */

void CSPMACtimer::prc_CSPMACtimer(){ /* Line 3 */
	//sc_uint<8> CSPMACOFECou_Data;
	
	if(Rst){
		cou=0;
		OFECou=0;
	}
	else
	{
		if(Enmactimer)
		{
			cou++;
			if (cou>=19)
			{
				cou=0;
				OFECou=OFECou.read()+1;
			}
			//OFECou=CSPMACOFECou_Data;
		}
		else
		{
			cou=0;
			OFECou=0;
		}
	}
}

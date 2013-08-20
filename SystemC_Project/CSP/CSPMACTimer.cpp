#include "CSPMACTimer.h"              /* Line 2 */

void CSPMACtimer::prc_CSPMACtimer(){ /* Line 3 */
	sc_uint<8> CSPMACOFECou_Data;
	sc_uint<8> cou;
	if(Rst){
		cou=0;
		CSPMACOFECou_Data=0;
	}
	else
	{
		if(Enmactimer)
		{
			cou++;
			if (cou>=19)
			{
				cou=0;
				CSPMACOFECou_Data++;
			}
			OFECou=CSPMACOFECou_Data;
		}
		else
		{
			cou=0;
			CSPMACOFECou_Data=0;
		}
	}
}

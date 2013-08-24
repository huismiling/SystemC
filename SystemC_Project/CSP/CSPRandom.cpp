#include "CSPRandom.h"              /* Line 2 */

void CSPRandom::prc_CSPRandom(){ /* Line 3 */
	sc_uint<8> CSPR_Data;
	switch (CSPY_out.read())
	{
	case 0:CSPR_Data="0x00";
		break;
	case 1:CSPR_Data=CSPR_in.read() & 0x1;
		break;
	case 2:CSPR_Data=CSPR_in.read() & 0x3;
		break;
	case 3:CSPR_Data=CSPR_in.read() & 0x7;
		break;
	case 4:CSPR_Data=CSPR_in.read() & 0xF;
		break;
	case 5:CSPR_Data=CSPR_in.read() & 0x1F;
		break;
	default:CSPR_Data="0xZZ";
	}
	CSPR_out=CSPR_Data;
}

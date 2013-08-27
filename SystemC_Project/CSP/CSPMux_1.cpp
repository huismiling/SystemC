#include "CSPMux_1.h"              /* Line 2 */

void CSPMux_1::prc_CSPMux_1(){ /* Line 3 */
	//sc_uint<8> CSPMux_1_Data;
	switch (Selmux_1.read())
	{
	case 0:CSPMux_1_out=CSPRFST_out.read();
		break;
	case 1:CSPMux_1_out=CSPPC_out.read();
		break;
	case 2:CSPMux_1_out=CSPCTRL_out.read();
		break;
	case 3:CSPMux_1_out=CSPT_out.read();
		break;
	case 4:CSPMux_1_out=CSPZ_out.read();
		break;
	case 5:CSPMux_1_out=CSPY_out.read();
		break;
	case 6:CSPMux_1_out=CSPX_out.read();
		break;
	default:CSPMux_1_out="0xZZ";
	}
	//CSPMux_1_out=CSPMux_1_Data;
}

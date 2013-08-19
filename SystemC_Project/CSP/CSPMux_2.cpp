#include "CSPMux_2.h"              /* Line 2 */

void CSPMux_2::prc_CSPMux_2(){ /* Line 3 */
	sc_uint<8> CSPMux_2_Data;
	switch (Selmux_2.read())
	{
	case 0:CSPMux_2_Data=Memory_out.read();
		break;
	case 1:CSPMux_2_Data=CSPMux_1_out.read();
		break;
	case 2:CSPMux_2_Data=CSPR_out.read();
		break;
	default:CSPMux_2_Data="0xZZ";
	}
	CSPMux_2_out=CSPMux_2_Data;
}

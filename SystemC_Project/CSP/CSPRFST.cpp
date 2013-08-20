#include "CSPRFST.h"              /* Line 2 */

void CSPRFST::prc_CSPRFST(){ /* Line 3 */
	sc_uint<8> CSPRFST_Data;
	if(Rst)
		CSPRFST_out=0;
	else if (Clk)
	{
		CSPRFST_Data=CSPRFST_in.read();
		CSPRFST_out=CSPRFST_Data;
	}
}

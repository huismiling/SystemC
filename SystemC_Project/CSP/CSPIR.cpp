#include "CSPIR.h"              /* Line 2 */

void CSPIR::prc_CSPIR(){ /* Line 3 */
	sc_uint<8> CSPIR_Data;
	if(Rst)
		Instruction=0;
	else if (Clk && Encspir)
	{
		CSPIR_Data=CSPIR_in.read();
	}
	Instruction=CSPIR_Data;
}

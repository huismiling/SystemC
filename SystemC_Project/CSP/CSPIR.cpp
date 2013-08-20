#include "CSPIR.h"              /* Line 2 */

void CSPIR::prc_CSPIR(){ /* Line 3 */
	sc_uint<8> CSPIR_Data;
	if(Rst)
		CSPIR_out=0;
	else if (Encspir)
	{
		CSPIR_out=CSPIR_in.read();
		//Instruction=CSPIR_Data;
	}
}

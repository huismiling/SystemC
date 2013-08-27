#include "CSPIR.h"              /* Line 2 */

void CSPIR::prc_CSPIR(){ /* Line 3 */
	if(Rst)
		CSPIR_out=0;
	else if (Encspir)
	{
		CSPIR_out=CSPIR_in.read();
	}
}

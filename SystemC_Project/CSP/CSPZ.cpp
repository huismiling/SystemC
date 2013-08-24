#include "CSPZ.h"              /* Line 2 */
#include <math.h>

void CSPZ::prc_CSPZ () { /* Line 3 */
	sc_uint<8> CSPZ_Data;
	if(Rst)
	{
		CSPZ_out=0;
		//CSPZ_Data=0;
	}
	else if (Clk)
	{
		if (Encspz)
			CSPZ_out=CSPZ_in.read();
		else if (Decz)
			CSPZ_out=CSPZ_out.read()-1;
		//CSPZ_out=CSPZ_Data;
	}
}

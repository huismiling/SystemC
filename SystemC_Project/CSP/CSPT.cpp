#include "CSPT.h"              /* Line 2 */
#include <math.h>

void CSPT::prc_CSPT () { /* Line 3 */
	sc_uint<8> CSPT_Data;
	if(Rst)
	{
		CSPT_out=0;
		//CSPT_Data=0;
	}
	else
	{
		if (Encspt)
			CSPT_out=CSPT_in.read();
		else if (Dect)
			CSPT_out=CSPT_out.read()-1;
		//CSPT_out=CSPT_Data;
	}
}

#include "CSPCTRL.h"              /* Line 2 */

void CSPCTRL::prc_CSPCTRL () { /* Line 3 */
	sc_uint<8> CSPCTRL_Data;
	if(Rst)
		CSPCTRL_out=0;
	else if (Encspctrl)
	{
		CSPCTRL_Data=CSPCTRL_in.read();
		CSPCTRL_out=CSPCTRL_Data;
	}
	
}

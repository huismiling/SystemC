#include "CSPCTRL.h"              /* Line 2 */

void CSPCTRL::prc_CSPCTRL () { /* Line 3 */
	if(Rst)
		CSPCTRL_out=0;
	else if (Encspctrl)
	{
		CSPCTRL_out=CSPCTRL_in.read();
	}
	
}

#include "CSPY.h"              /* Line 2 */
#include <math.h>

void CSPY::prc_CSPY () { /* Line 3 */
	sc_uint<8> CSPY_Data;
	if(Rst)
	{
		CSPY_out=0;
	}
	else
	{
		if (Encspy)
		{
			CSPY_out=CSPY_in.read();
			//CSPY_out=CSPY_Data;
		}
		else if (Incy)
		{
			CSPY_out=CSPY_out.read()+1;
			//CSPY_out=CSPY_Data;
		}
		else if (Decy)
		{
			CSPY_out=CSPY_out.read()-1;
			//CSPY_out=CSPY_Data;
		}
		
	}
}

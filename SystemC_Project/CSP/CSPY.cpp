#include "CSPY.h"              /* Line 2 */
#include <math.h>

void CSPY::prc_CSPY () { /* Line 3 */
	sc_uint<8> CSPY_Data;
	if(Rst)
	{
		CSPY_Data=0;
	}
	else
	{
		if (Encspy)
		{
			CSPY_Data=CSPY_in.read();
			
		}
		else if (Incy)
		{
			CSPY_Data=CSPY_Data+1;
			//CSPY_out=CSPY_Data;
		}
		else if (Decy)
		{
			CSPY_Data=CSPY_Data-1;
			//CSPY_out=CSPY_Data;
		}
		CSPY_out=CSPY_Data;
	}
}

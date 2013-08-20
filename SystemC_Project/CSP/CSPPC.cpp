#include "CSPPC.h"              /* Line 2 */
#include <math.h>

void CSPPC::prc_CSPPC () { /* Line 3 */
	sc_uint<8> CSPPC_Data;
	if(Rst)
		CSPPC_out=0;
	else if (Encsppc)
	{
		CSPPC_Data=CSPPC_in.read() + S.read();
		CSPPC_out=CSPPC_Data;
	}
}

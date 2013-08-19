#include "CSPZeroFlag.h"              /* Line 2 */

void CSPZeroFlag::prc_CSPZeroFlag(){ /* Line 3 */
	bool CSPC_Data;
	switch (IR.read()&0x7)
	{
	case 0:CSPC_Data=CCA_Active.read();
		break;
	case 2:CSPC_Data=Tx_Active.read();
		break;
	case 6:CSPC_Data=(CSPZ_out.read()!=0);
		break;
	default:CSPC_Data="Z";
	}
	CSPC_out=(IR.read()[3])^(CSPC_Data);
}

#ifndef _CSPZeroFlag_H
#define _CSPZeroFlag_H

#include "systemc.h"

SC_MODULE (CSPZeroFlag) {
	sc_in< sc_uint<8> > IR;
	sc_in< bool > CCA_Active, Tx_Active;
	sc_in< sc_uint<8> > CSPZ_out;
	sc_out< bool > CSPC_out;

	void prc_CSPZeroFlag ();

	SC_CTOR (CSPZeroFlag) {
		SC_METHOD (prc_CSPZeroFlag);
		sensitive << IR << CCA_Active << Tx_Active << CSPZ_out;
	}
};

#endif


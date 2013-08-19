#ifndef _CSPMux_2_H
#define _CSPMux_2_H

#include "systemc.h"

SC_MODULE (CSPMux_2) {
	sc_in< sc_uint<2> > Selmux_2;
	sc_in< sc_uint<8> > Memory_out,CSPMux_1_out,CSPR_out;
	sc_out< sc_uint<8> > CSPMux_2_out;

	void prc_CSPMux_2 ();

	SC_CTOR (CSPMux_2) {
		SC_METHOD (prc_CSPMux_2);
		sensitive << Selmux_2 << Memory_out << CSPMux_1_out << CSPR_out;
	}
};

#endif


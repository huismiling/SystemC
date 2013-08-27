#ifndef _CSPMux_1_H
#define _CSPMux_1_H

#include "systemc.h"

SC_MODULE (CSPMux_1) {
	sc_in< sc_uint<3> > Selmux_1;
	sc_in< sc_uint<8> > CSPRFST_out,CSPPC_out,CSPCTRL_out,CSPT_out,CSPZ_out,CSPY_out,CSPX_out;
	sc_out< sc_uint<8> > CSPMux_1_out;

	void prc_CSPMux_1();

	SC_CTOR (CSPMux_1) {
		SC_METHOD (prc_CSPMux_1);
		sensitive << Selmux_1 << CSPRFST_out << CSPPC_out << CSPCTRL_out << CSPT_out << CSPZ_out << CSPY_out << CSPX_out;
	}
};

#endif


#ifndef _CSPCTRL_H
#define _CSPCTRL_H

#include "systemc.h"

SC_MODULE (CSPCTRL) {
	sc_in<bool> Clk, Rst, Encspctrl;
	sc_in< sc_uint<8> > CSPCTRL_in;
	sc_out< sc_uint<8> > CSPCTRL_out;

	void prc_CSPCTRL ();

	SC_CTOR (CSPCTRL) {
		SC_METHOD (prc_CSPCTRL);
		sensitive_pos << Clk << Rst;
	}
};

#endif


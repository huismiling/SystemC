#ifndef _CSPX_H
#define _CSPX_H

#include "systemc.h"

SC_MODULE (CSPX) {
	sc_in<bool> Clk, Rst, Encspx;
	sc_in< sc_uint<8> > CSPX_in;
	sc_out< sc_uint<8> > CSPX_out;

	void prc_CSPX ();

	SC_CTOR (CSPX) {
		SC_METHOD (prc_CSPX);
		sensitive_pos << Clk << Rst;
	}
};

#endif


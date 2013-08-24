#ifndef _CSPIR_H
#define _CSPIR_H

#include "systemc.h"

SC_MODULE (CSPIR) {
	sc_in<bool> Clk, Rst, Encspir;
	sc_in< sc_uint<8> > CSPIR_in;
	sc_out< sc_uint<8> > CSPIR_out;

	void prc_CSPIR ();

	SC_CTOR (CSPIR) {
		SC_METHOD (prc_CSPIR);
		sensitive_pos << Clk << Rst;
	}
};

#endif


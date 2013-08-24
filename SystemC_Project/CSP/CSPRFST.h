#ifndef _CSPRFST_H
#define _CSPRFST_H

#include "systemc.h"

SC_MODULE (CSPRFST) {
	sc_in<bool> Clk, Rst;
	sc_in< sc_uint<8> > CSPRFST_in;
	sc_out< sc_uint<8> > CSPRFST_out;

	void prc_CSPRFST ();

	SC_CTOR (CSPRFST) {
		SC_METHOD (prc_CSPRFST);
		sensitive_pos << Clk << Rst;
	}
};

#endif


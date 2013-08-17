#ifndef _CSPPC_H
#define _CSPPC_H

#include "systemc.h"

SC_MODULE (CSPPC) {
	sc_in<bool> Clk, Rst, Encsppc;
	sc_in< sc_uint<8> > CSPPC_in;
	sc_in< sc_uint<3> > S;
	sc_out< sc_uint<8> > CSPPC_out;

	void prc_CSPPC ();

	SC_CTOR (CSPPC) {
		SC_METHOD (prc_CSPPC);
		sensitive << Clk << Rst;
	}
};

#endif


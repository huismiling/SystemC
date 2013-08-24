#ifndef _CSPZ_H
#define _CSPZ_H

#include "systemc.h"

SC_MODULE (CSPZ) {
	sc_in<bool> Clk, Rst, Encspz, Decz;
	sc_in< sc_uint<8> > CSPZ_in;
	sc_out< sc_uint<8> > CSPZ_out;

	void prc_CSPZ ();

	SC_CTOR (CSPZ) {
		SC_METHOD (prc_CSPZ);
		sensitive_pos << Clk << Rst;
	}
};

#endif


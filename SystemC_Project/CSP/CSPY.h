#ifndef _CSPY_H
#define _CSPY_H

#include "systemc.h"

SC_MODULE (CSPY) {
	sc_in<bool> Clk, Rst, Encspy, Incy, Decy;
	sc_in< sc_uint<8> > CSPY_in;
	sc_out< sc_uint<8> > CSPY_out;

	void prc_CSPY ();

	SC_CTOR (CSPY) {
		SC_METHOD (prc_CSPY);
		sensitive_pos << Clk << Rst;
	}
};

#endif


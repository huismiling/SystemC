#ifndef _CSPT_H
#define _CSPT_H

#include "systemc.h"

SC_MODULE (CSPT) {
	sc_in<bool> Clk, Rst, Encspt, Dect;
	sc_in< sc_uint<8> > CSPT_in;
	sc_out< sc_uint<8> > CSPT_out;

	void prc_CSPT ();

	SC_CTOR (CSPT) {
		SC_METHOD (prc_CSPT);
		sensitive << Clk << Rst;
	}
};

#endif


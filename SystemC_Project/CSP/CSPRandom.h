#ifndef _CSPRandom_H
#define _CSPRandom_H

#include "systemc.h"

SC_MODULE (CSPRandom) {
	sc_in< sc_uint<8> > CSPY_out;
	sc_in< sc_uint<16> > CSPR_in;
	sc_out< sc_uint<8> > CSPR_out;

	void prc_CSPRandom ();

	SC_CTOR (CSPRandom) {
		SC_METHOD (prc_CSPRandom);
		sensitive << CSPY_out << CSPR_in;
	}
};

#endif


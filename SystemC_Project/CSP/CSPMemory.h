#ifndef _CSPMemory_H
#define _CSPMemory_H

#include "systemc.h"

SC_MODULE (CSPMemory) {
	sc_in<bool> Clk, Rst, MEM_Read;
	sc_in< sc_uint<8> > MEM_Address;
	sc_out< sc_uint<8> > Memory_out;



	void prc_CSPMemory ();

	SC_CTOR (CSPMemory) {
		SC_METHOD (prc_CSPMemory);
		sensitive_pos << Clk << Rst;
	}
};

#endif



#include "systemc.h"

SC_MODULE (driver) {
	sc_out<bool> Clk, Rst, Encspx;
	sc_out< sc_uint<8> > d_out;

	void prc_driver (); 

	SC_CTOR (driver) {
		SC_THREAD (prc_driver);
	}
};

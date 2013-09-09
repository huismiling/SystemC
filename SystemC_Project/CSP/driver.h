
#include "systemc.h"

SC_MODULE (driver) {
	sc_out<bool> Clk, Rst, Tx_Active, CCA_Active;
	sc_out< sc_uint<8> > RFST_in;// CSPIR_out, , MUX OFECou,, C_out
	sc_out< sc_uint<16> > Random_in;

	//sc_uint<8> cou;

	void prc_driver (); 

	SC_CTOR (driver) {
		SC_THREAD (prc_driver);
	}
};

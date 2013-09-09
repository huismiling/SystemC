
#include "systemc.h"

SC_MODULE (driver) {
	sc_out<bool> Clk, Rst, C_out, Tx_Active, CCA_Active;
	sc_out< sc_uint<8> > OFECou,RFST_in, MUX;// CSPIR_out, 
	sc_out< sc_uint<16> > Random_in;

	//sc_uint<8> cou;

	void prc_driver (); 

	SC_CTOR (driver) {
		SC_THREAD (prc_driver);
	}
};

#ifndef _CSPControl_H
#define _CSPControl_H

#include "systemc.h"

SC_MODULE (CSPControl) {
	sc_in<bool> Clk, Rst, C_out;
	sc_in< sc_uint<8> > OFECou, Instruction, MUX;
	sc_out<bool> Encspx, Encspy, Incy, Decy, Encspz, Decz, Encspt, Dect, Encspctrl, Enpc, Enir, MEM_Read, Enmactimer;
	sc_out< sc_uint<3> > S, Selmux_1;
	sc_out< sc_uint<2> > Selmux_2;
	sc_out<bool> Txcaln, Txon, Txoncca, ackset, Txoff, flush_tx, Rxon, Rxoff, flush_rx;
	sc_out< sc_uint<32> > i;

	sc_out<sc_uint<4> > W;

	sc_signal<bool> Clk_en;
	sc_signal<bool> S_IS;

	void prc_CSPControl1 ();
	void prc_CSPControl2 ();
	void prc_CSPControl3 ();

	SC_CTOR (CSPControl) {
		SC_METHOD (prc_CSPControl1);
		sensitive_pos << Clk << Rst;

		SC_METHOD (prc_CSPControl2);
		sensitive_neg << Clk;
		sensitive_pos << Rst;

		SC_METHOD (prc_CSPControl3);
		sensitive <<i;
	}
};

#endif


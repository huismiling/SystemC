#ifndef _CSPTOP_H
#define _CSPTOP_H

#include "systemc.h"
#include "IncludeFiles.h"

SC_MODULE (CSPTOP) {
	sc_in<bool> Clk, Rst;
	sc_in<bool> Tx_Active, CCA_Active;
	sc_in< sc_uint<8> > RFST_in;
	sc_in< sc_uint<16> > Random_in;
	sc_out<bool> Txcaln, Txon, Txoncca, ackset, Txoff, flush_tx, Rxon, Rxoff, flush_rx;
	sc_out< sc_uint<8> > MUX;
	sc_out< sc_uint<32> > i;

	sc_signal<bool> Encspx, Encspy, Incy, Decy, Encspz, Decz, Encspt, Dect, Encspctrl, Enpc, Enir, MEM_Read, Enmactimer, CSPC_out;
	sc_signal<sc_uint<3> > S, CSPSelmux_1;
	sc_signal< sc_uint<2> > CSPSelmux_2;
	sc_signal< sc_uint<8> > CSPX_out, CSPY_out, CSPZ_out, CSPT_out, CSPCTRL_out, CSPPC_out, CSPIR_out, RFST_out, CSPMux_1_out,
							Memory_out, CSPR_out, OFECou;

	void topmethod();

	CSPX X;
	CSPY Y;
	CSPZ Z;
	CSPT T;
	CSPCTRL CTRL;
	CSPPC PC;
	CSPIR IR;
	CSPRFST RFST;
	CSPMux_1 Mux_1;
	CSPMemory MEM;
	CSPRandom Random;
	CSPMux_2 Mux_2;
	CSPZeroFlag Zeroflag;
	CSPMACTimer MACTimer;
	CSPControl Control;

	SC_CTOR (CSPTOP):
		X("CSPX"),
		Y("CSPY"),
		Z("CSPZ"),
		T("CSPT"),
		CTRL("CSPCTRL"),
		PC("CSPPC"),
		IR("CSPIR"),
		RFST("CSPRFST"),
		Mux_1("CSPMux_1"),
		MEM("CSPMEM"),
		Random("CSPRandom"),
		Mux_2("CSPMux_2"),
		Zeroflag("CSPZeroflag"),
		MACTimer("CSPMACTimer"),
		Control("CSPControl")
	{
		X.Clk(Clk);
		X.Rst(Rst);
		X.Encspx(Encspx);
		X.CSPX_in(MUX);
		X.CSPX_out(CSPX_out);

		Y.Clk(Clk);
		Y.Rst(Rst);
		Y.Encspy(Encspy);
		Y.Incy(Incy);
		Y.Decy(Decy);
		Y.CSPY_in(MUX);
		Y.CSPY_out(CSPY_out);

		Z.Clk(Clk);
		Z.Rst(Rst);
		Z.Encspz(Encspz);
		Z.Decz(Decz);
		Z.CSPZ_in(MUX);
		Z.CSPZ_out(CSPZ_out);

		T.Clk(Clk);
		T.Rst(Rst);
		T.Encspt(Encspt);
		T.Dect(Dect);
		T.CSPT_in(MUX);
		T.CSPT_out(CSPT_out);

		CTRL.Clk(Clk);
		CTRL.Rst(Rst);
		CTRL.Encspctrl(Encspctrl);
		CTRL.CSPCTRL_in(MUX);
		CTRL.CSPCTRL_out(CSPCTRL_out);

		PC.Clk(Clk);
		PC.Rst(Rst);
		PC.Encsppc(Enpc);
		PC.S(S);
		PC.CSPPC_in(MUX);
		PC.CSPPC_out(CSPPC_out);

		IR.Clk(Clk);
		IR.Rst(Rst);
		IR.Encspir(Enir);
		IR.CSPIR_in(MUX);
		IR.CSPIR_out(CSPIR_out);

		RFST.Clk(Clk);
		RFST.Rst(Rst);
		RFST.CSPRFST_in(RFST_in);
		RFST.CSPRFST_out(RFST_out);

		Mux_1.Selmux_1(CSPSelmux_1);
		Mux_1.CSPRFST_out(RFST_out);
		Mux_1.CSPPC_out(CSPPC_out);
		Mux_1.CSPCTRL_out(CSPCTRL_out);
		Mux_1.CSPT_out(CSPT_out);
		Mux_1.CSPZ_out(CSPZ_out);
		Mux_1.CSPY_out(CSPY_out);
		Mux_1.CSPX_out(CSPX_out);
		Mux_1.CSPMux_1_out(CSPMux_1_out);

		MEM.Clk(Clk);
		MEM.Rst(Rst);
		MEM.MEM_Read(MEM_Read);
		MEM.MEM_Address(CSPMux_1_out);
		MEM.Memory_out(Memory_out);
		
		Random.CSPY_out(CSPY_out);
		Random.CSPR_in(Random_in);
		Random.CSPR_out(CSPR_out);

		Mux_2.Selmux_2(CSPSelmux_2);
		Mux_2.Memory_out(Memory_out);
		Mux_2.CSPMux_1_out(CSPMux_1_out);
		Mux_2.CSPR_out(CSPR_out);
		Mux_2.CSPMux_2_out(MUX);

		Zeroflag.CSPZ_out(CSPZ_out);
		Zeroflag.IR(CSPIR_out);
		Zeroflag.Tx_Active(Tx_Active);
		Zeroflag.CCA_Active(CCA_Active);
		Zeroflag.CSPC_out(CSPC_out);

		MACTimer.Clk(Clk);
		MACTimer.Rst(Rst);
		MACTimer.Enmactimer(Enmactimer);
		MACTimer.OFECou(OFECou);

		Control.Clk(Clk);
		Control.Rst(Rst);
		Control.OFECou(OFECou);
		Control.Instruction(CSPIR_out);
		Control.MUX(MUX);
		Control.C_out(CSPC_out);

		Control.i(i);
		Control.Encspx(Encspx);
		Control.Encspy(Encspy);
		Control.Incy(Incy);
		Control.Decy(Decy);
		Control.Encspz(Encspz);
		Control.Decz(Decz);
		Control.Encspt(Encspt);
		Control.Dect(Dect);
		Control.Encspctrl(Encspctrl);
		Control.Enpc(Enpc);
		Control.S(S);
		Control.Enir(Enir);
		Control.Selmux_1(CSPSelmux_1);
		Control.Selmux_2(CSPSelmux_2);
		Control.MEM_Read(MEM_Read);
		Control.Enmactimer(Enmactimer);
		Control.Txcaln(Txcaln);
		Control.Txon(Txon);
		Control.Txoncca(Txoncca);
		Control.ackset(ackset);
		Control.Txoff(Txoff);
		Control.flush_tx(flush_tx);
		Control.Rxon(Rxon);
		Control.Rxoff(Rxoff);
		Control.flush_rx(flush_rx);

		SC_METHOD(topmethod)
			sensitive_pos<< Clk <<Rst;
	}
};

#endif


#include <systemc.h>
#include "driver.h"
#include "IncludeFiles.h"

int sc_main(int, char**){
	sc_signal<bool> Clk, Rst, Tx_Active, CCA_Active;
	sc_signal< sc_uint<8> > RFST_in, MUX;
	sc_signal< sc_uint<16> >Random_in;
	sc_signal<bool> Txcaln, Txon, Txoncca, ackset, Txoff, flush_tx, Rxon, Rxoff, flush_rx;
	sc_signal< sc_uint<32> > i;

	sc_signal<bool> Encspx, Encspy, Incy, Decy, Encspz, Decz, Encspt, Dect, Encspctrl, Enpc, Enir, MEM_Read, Enmactimer, CSPC_out;
	sc_signal<sc_uint<3> > S, CSPSelmux_1;
	sc_signal< sc_uint<2> > CSPSelmux_2;
	sc_signal< sc_uint<8> > CSPX_out, CSPY_out, CSPZ_out, CSPT_out, CSPCTRL_out, CSPPC_out, CSPIR_out, RFST_out, CSPMux_1_out,
		Memory_out, CSPR_out, OFECou;

	CSPControl Control("CSPControl");
	/*DUT.Clk(Clk);
	DUT.Rst(Rst);
	DUT.Tx_Active(Tx_Active);
	DUT.CCA_Active(CCA_Active);
	DUT.RFST_in(RFST_in);
	DUT.Random_in(Random_in);
	DUT.MUX(MUX);
	DUT.i(i);
	DUT.Txcaln(Txcaln);
	DUT.Txon(Txon);
	DUT.Txoncca(Txoncca);
	DUT.ackset(ackset);
	DUT.Txoff(Txoff);
	DUT.flush_tx(flush_tx);
	DUT.Rxon(Rxon);
	DUT.Rxoff(Rxoff);
	DUT.flush_rx(flush_rx);
	*/
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


	driver d("driver");
	d.Clk(Clk);
	d.Rst(Rst);
	//d.Tx_Active(Tx_Active);
	//d.CCA_Active(CCA_Active);
	//d.RFST_in(RFST_in);
	//d.Random_in(Random_in);
	d.CSPIR_out(CSPIR_out);
	d.OFECou(OFECou);
	d.MUX(MUX);
	d.C_out(CSPC_out);

	// trace file creation
/*	sc_trace_file *tf = sc_create_vcd_trace_file("CSPTOP");
	sc_trace(tf,DUT.Clk, "Clk");
	sc_trace(tf,DUT.Rst, "Rst");
	sc_trace(tf,DUT.Tx_Active, "Tx_Active");
	sc_trace(tf,DUT.CCA_Active, "CCA_Active");
	sc_trace(tf,DUT.RFST_in, "RFST_in");
	sc_trace(tf,DUT.MUX, "MUX");
	sc_trace(tf,DUT.Random_in, "Random_in");
	sc_trace(tf,DUT.i, "i");
	sc_trace(tf,DUT.Txcaln, "Txcaln");
	sc_trace(tf,DUT.Txon, "Txon");
	sc_trace(tf,DUT.Txoncca, "Txoncca");
	sc_trace(tf,DUT.ackset, "ackset");
	sc_trace(tf,DUT.Txoff, "Txoff");
	sc_trace(tf,DUT.flush_tx, "flush_tx");
	sc_trace(tf,DUT.Rxon, "Rxon");
	sc_trace(tf,DUT.Rxoff, "Rxoff");
	sc_trace(tf,DUT.flush_rx, "flush_rx");
	*/

	sc_trace_file *tf = sc_create_vcd_trace_file("CSPControl");
	sc_trace(tf,Control.Clk, "Clk");
	sc_trace(tf,Control.Rst, "Rst");
	sc_trace(tf,Control.OFECou, "Tx_Active");
	sc_trace(tf,Control.Instruction, "Instruction");
	sc_trace(tf,Control.MUX, "MUX");
	sc_trace(tf,Control.C_out, "C_out");
	//sc_trace(tf,Control.Random_in, "Random_in");
	sc_trace(tf,Control.i, "i");

	sc_start(100,SC_NS);
	sc_close_vcd_trace_file(tf);
	system("pause");
	return 0;
}


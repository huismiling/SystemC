#include <systemc.h>
#include "driver.h"
#include "IncludeFiles.h"

int sc_main(int, char**){
	sc_signal<bool> Clk, Rst, En, Inc, Dec;
	sc_signal< sc_uint<3> > PC_S,Selmux;
	sc_signal< sc_uint<8> > TestData;
	sc_signal< sc_uint<8> > Test_out;

	CSPMux_1 DUT("CSPMux_1");
	DUT.Selmux_1(Selmux);
	DUT.CSPRFST_out(TestData);
	DUT.CSPPC_out(TestData);
	DUT.CSPCTRL_out(TestData);
	DUT.CSPT_out(TestData);
	DUT.CSPZ_out(TestData);
	DUT.CSPY_out(TestData);
	DUT.CSPX_out(TestData);
	//DUT.Incy(Incy);
	//DUT.S(PC_S);
	//DUT.MEM_Address(TestData);
	DUT.CSPMux_1_out(Test_out);

	driver d("driver");
	d.Clk(Clk);
	d.Rst(Rst);
	d.Inc(Inc);
	d.Dec(Dec);
	d.En(En);
	d.d_out3(Selmux);
	d.d_out8(TestData);

	// trace file creation
	sc_trace_file *tf = sc_create_vcd_trace_file("CSPMux_1");
	//sc_trace(tf,DUT.Clk, "Clk");
	//sc_trace(tf,DUT.Rst, "Rst");
	sc_trace(tf,DUT.Selmux_1, "Selmux_1");
	sc_trace(tf,DUT.CSPRFST_out, "CSPRFST_out");
	sc_trace(tf,DUT.CSPPC_out, "CSPPC_out");
	sc_trace(tf,DUT.CSPCTRL_out, "CSPCTRL_out");
	sc_trace(tf,DUT.CSPT_out, "CSPT_out");
	sc_trace(tf,DUT.CSPZ_out, "CSPZ_out");
	sc_trace(tf,DUT.CSPY_out, "CSPY_out");
	sc_trace(tf,DUT.CSPX_out, "CSPX_out");
	//sc_trace(tf,DUT.Dect, "Dect");
	//sc_trace(tf,DUT.S, "S");
	//sc_trace(tf,DUT.Enmactimer, "Enmactimer");
	//sc_trace(tf,DUT.MEM_Address, "MEM_Address");
	sc_trace(tf,DUT.CSPMux_1_out, "CSPMux_1_out");

	sc_start(100,SC_NS);
	sc_close_vcd_trace_file(tf);
	system("pause");
	return 0;
}


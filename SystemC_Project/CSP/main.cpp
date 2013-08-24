#include <systemc.h>
#include "driver.h"
#include "IncludeFiles.h"

int sc_main(int, char**){
	sc_signal<bool> Clk, Rst, En, Inc, Dec;
	sc_signal< sc_uint<3> > PC_S;
	sc_signal< sc_uint<8> > TestData;
	sc_signal< sc_uint<8> > Test_out;

	CSPMemory DUT("CSPMemory");
	DUT.Clk(Clk);
	DUT.Rst(Rst);
	DUT.MEM_Read(En);
	//DUT.Incy(Incy);
	//DUT.S(PC_S);
	DUT.MEM_Address(TestData);
	DUT.Memory_out(Test_out);

	driver d("driver");
	d.Clk(Clk);
	d.Rst(Rst);
	d.Inc(Inc);
	d.Dec(Dec);
	d.En(En);
	d.PC_S(PC_S);
	d.d_out(TestData);

	// trace file creation
	sc_trace_file *tf = sc_create_vcd_trace_file("CSPMemory");
	sc_trace(tf,DUT.Clk, "Clk");
	sc_trace(tf,DUT.Rst, "Rst");
	//sc_trace(tf,DUT.Incy, "Incy");
	//sc_trace(tf,DUT.Dect, "Dect");
	//sc_trace(tf,DUT.S, "S");
	sc_trace(tf,DUT.MEM_Read, "MEM_Read");
	sc_trace(tf,DUT.MEM_Address, "MEM_Address");
	sc_trace(tf,DUT.Memory_out, "Memory_out");

	sc_start(500,SC_NS);
	sc_close_vcd_trace_file(tf);
	system("pause");
	return 0;
}


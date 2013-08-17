#include <systemc.h>
#include "driver.h"
#include "CSPX.h"

int sc_main(int, char**){
	sc_signal<bool> Clk, Rst, Encspx;
	sc_signal< sc_uint<8> > CSPX_in;
	sc_signal< sc_uint<8> > CSPX_out;

	CSPX X("CSPX");
	X.Clk(Clk);
	X.Rst(Rst);
	X.Encspx(Encspx);
	X.CSPX_in(CSPX_in);
	X.CSPX_out(CSPX_out);

	driver d("driver");
	d.Clk(Clk);
	d.Rst(Rst);
	d.Encspx(Encspx);
	d.d_out(CSPX_in);

	// trace file creation
	sc_trace_file *tf = sc_create_vcd_trace_file("CSPX");
	sc_trace(tf,X.Clk, "Clk");
	sc_trace(tf,X.Rst, "Rst");
	sc_trace(tf,X.Encspx, "Encspx");
	sc_trace(tf,X.CSPX_in, "CSPX_in");
	sc_trace(tf,X.CSPX_out, "CSPX_out");

	sc_start(200,SC_NS);
	sc_close_vcd_trace_file(tf);
	system("pause");
	return 0;
}


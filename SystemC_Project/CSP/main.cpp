#include <systemc.h>
#include "driver.h"
#include "IncludeFiles.h"

int sc_main(int, char**){
	sc_signal<bool> Clk, Rst, 
					Encspy, Incy, Decy, 
					Encspz, Decz, 
					Encspt, Dect,
					Encspctrl;
	sc_signal< sc_uint<8> > TestData;
	sc_signal< sc_uint<8> > CSPY_out;

	CSPY Y("CSPY");
	Y.Clk(Clk);
	Y.Rst(Rst);
	Y.Encspy(Encspy);
	Y.Incy(Incy);
	Y.Decy(Decy);
	Y.CSPY_in(TestData);
	Y.CSPY_out(CSPY_out);

	driver d("driver");
	d.Clk(Clk);
	d.Rst(Rst);
	d.Inc(Incy);
	d.Dec(Decy);
	d.En(Encspy);
	d.d_out(TestData);

	// trace file creation
	sc_trace_file *tf = sc_create_vcd_trace_file("CSPY");
	sc_trace(tf,Y.Clk, "Clk");
	sc_trace(tf,Y.Rst, "Rst");
	sc_trace(tf,Y.Incy, "Incy");
	sc_trace(tf,Y.Decy, "Decy");
	sc_trace(tf,Y.Encspy, "Encspy");
	sc_trace(tf,Y.CSPY_in, "CSPY_in");
	sc_trace(tf,Y.CSPY_out, "CSPY_out");

	sc_start(500,SC_NS);
	sc_close_vcd_trace_file(tf);
	system("pause");
	return 0;
}


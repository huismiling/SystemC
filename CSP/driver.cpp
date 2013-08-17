#include "driver.h"

void driver::prc_driver () {
	Rst=1;
	wait (10, SC_NS);
	Rst=0;
	Clk=0;
	wait (5, SC_NS);
	d_out=rand()%256;
	while (1) {
		Clk=!Clk;
		wait (5, SC_NS);
		Clk=!Clk;
		wait (5, SC_NS);
		Encspx=rand()%2;
		d_out=rand()%256;
	}
}
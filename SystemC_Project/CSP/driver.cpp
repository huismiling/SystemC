#include "driver.h"
#include "time.h"

void driver::prc_driver () {
	srand(time(NULL));
	Rst=1;
	wait (10, SC_NS);
	Rst=0;
	Clk=1;
	wait (5, SC_NS);
	d_out8=0;//rand()%256;
	while (1) {
		Clk=!Clk;
		wait (5, SC_NS);
		Clk=!Clk;
		wait (5, SC_NS);
		d_out3=rand()%8;
		//Inc=rand()%2;
		//Dec=rand()%2;
		//En=rand()%2;
		d_out8=d_out8.read()+1;//rand()%256;
	}
}
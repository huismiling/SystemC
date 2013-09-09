#include "driver.h"
#include "time.h"

void driver::prc_driver () {
	sc_uint<8> MEM_Data[256]={
		0xBA,0xBB,0x22,0xC1,0xB8,0x50,0xB8,0x30,0xC2,0xC0,0x12,0xC3,0xB5,0xBC,0xBF,0xAE
	};
	srand(time(NULL));
	Rst=1;
	OFECou=3;
	MUX=4;
	//cou=0;
	wait (10, SC_NS);
	Rst=0;
	Clk=0;
	//CSPIR_out=0xE0;
	wait (5, SC_NS);
	//d_out8=0;//rand()%256;
	while (1) {
		Clk=!Clk;
		wait (5, SC_NS);
		Clk=!Clk;
		wait (5, SC_NS);
		C_out=0;
		Tx_Active=rand()%2;
		CCA_Active=rand()%2;
		Random_in=rand()&0xFFFF;
		//cou++;
		//CSPIR_out=MEM_Data[cou/4];
		//Inc=rand()%2;
		//Dec=rand()%2;
		//En=rand()%2;
		//d_out8=d_out8.read()+1;//rand()%256;
	}
}
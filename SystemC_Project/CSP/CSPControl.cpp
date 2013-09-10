#include "CSPControl.h"              /* Line 2 */

void CSPControl::prc_CSPControl1(){ /* Line 3 */
	if(Rst)
	{
		W="1000";
	}
	else
	{
		if(!Clk_en & !S_IS)
		{
			W=(W.read().range(2,0),W.read()[3]);
		}
	}
}

void CSPControl::prc_CSPControl2(){ 
	sc_uint<8> TMP;
	sc_uint<32> iTMP;
	TMP=Instruction.read();
	if(Rst)
	{
		i="0x00010400";
		S_IS=1;
		Clk_en=0;
	}
	else
	{
		if(S_IS==1)
		{
			switch(TMP)
			{
				case 0xE0:
					S_IS=0;
					i="0x0000EC00";
					break;
				case 0xE1:
					i="0x00010404";
					break;
				case 0xE2:
					i="0x00010480";
					break;
				case 0xE3:
					i="0x00010412";
					break;
				case 0xE4:
					i="0x00010401";
					break;
				case 0xE5:
					i="0x00010408";
					break;
				default:
					i="0x00010400";
			}
		}
		else //(!S_IS)
		{
			if(W.read()&0x01)
				i="0x00003000";
			else if(W.read()&0x02)
				i="0x0003E000";
			else if(W.read()&0x04)
			{
				if (TMP[7]==0)
				{
					if(C_out)
						i=("000000000000",TMP.range(6,4),"01110110000000000");
					else
						i="0x0000EC00";
				} 
				else if(TMP.range(7,5)==4)
				{
					if(Clk_en==0)
					{
						i="0x0000EE00";
						Clk_en=1;
					}
					else if(OFECou.read()>=TMP.range(4,0))
						Clk_en=0;
				}
				else if (TMP.range(7,4)==10)
				{
					if(C_out)
						i="0x00104400";
					else
						i="0x0000EC00";
				}
				else if(TMP.range(7,3)==0x16)
					i="0x0000A400";
				else
					switch(TMP)
				{
					case 0xB8:
						if(Clk_en==0)
						{
							i="0x0000EE00";
							Clk_en=1;
						}
						else
							if(OFECou.read()>=1)
								Clk_en=0;
						break;
					case 0xBB:
						if(Clk_en==0)
						{
							i="0x0000C600";
							Clk_en=1;
						}
						else
							if(OFECou.read()>=MUX.read())
								Clk_en=0;
						break;
					case 0xBA:
						i="0x00202400";
						break;
					case 0xBD:
						i="0x0800EC00";
						break;
					case 0xBE:
						i="0x0400EC00";
						break;
					case 0xBF:
						i="0x0100EC00";
						break;
					case 0xBC:
						i="0x2000E800";
						break;
					case 0xC0:
						S_IS=1;
						i="0x00010400";
						break;
					case 0xC1:
						i="0x0000EC04";
						break;
					case 0xC2:
						i="0x0000EC80";
						break;
					case 0xC3:
						i="0x0000EC12";
						break;
					case 0xC4:
						i="0x0000EC01";
						break;
					case 0xC5:
						i="0x0000EC08";
						break;
					default:
						i="0x0000EC00";
				}//switch
			}//W[2]
			else if(W.read()&0x08)
			{
				if (TMP.range(7,3)==0x16)
				{
					if(MUX.read()<TMP.range(2,0))
						i="0x0800EC00";
					else
						i="0x0000EC00";
				}
			}//W[3]
		}
	}
		iTMP=i.read();
		Encspx		=iTMP[29];
		Encspy		=iTMP[28];
		Incy		=iTMP[27];
		Decy		=iTMP[26];
		Encspz		=iTMP[25];
		Decz		=iTMP[24];
		Encspt		=iTMP[23];
		Dect		=iTMP[22];
		Encspctrl	=iTMP[21];
		Enpc		=iTMP[20];
		S			=iTMP.range(19,17);//(i[19],i[18],i[17]);
		Enir		=iTMP[16];
		Selmux_1	=iTMP.range(15,13);
		MEM_Read	=iTMP[12];
		Selmux_2	=iTMP.range(11,10);
		Enmactimer	=iTMP[9];
		Txcaln		=iTMP[8];
		Txon		=iTMP[7];
		Txoncca		=iTMP[6];
		ackset		=iTMP[5];
		Txoff		=iTMP[4];
		flush_tx	=iTMP[3];
		Rxon		=iTMP[2];
		Rxoff		=iTMP[1];
		flush_rx	=iTMP[0];
}
#include "CSPControl.h"              /* Line 2 */

void CSPControl::prc_CSPControl1(){ /* Line 3 */
	if(Rst)
	{
		W="0001";
	}
	else
	{
		if(!Clk_en & !S_IS)
		{
			W=(W.range(2,0),W[3]);
		}
	}
}

void CSPControl::prc_CSPControl2(){ 
	sc_uint<8> TMP;
	TMP=Instruction.read();
	if(Rst)
	{
		i="0x00010400";
		S_IS="1";
		Clk_en="0";
	}
	else
	{
		if(S_IS)
		{
			switch(TMP)
			{
				case 0xE0:
					S_IS="0";
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
			if(W[0])
				i="0x00003000";
			else if(W[1])
				i="0x0003E000";
			else if(W[2])
			{
				if (TMP[7])
				{
					if(C_out)
						i=("0000000000",TMP.range(6,4),"01110110000000000");
					else
						i="0x0000EC000";
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
			else if(W[3])
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
		Encspx=i[29];
		Encspy=i[28];
		Incy=i[27];
		Decy=i[26];
		Encspz=i[25];
		Decz=i[24];
		Encspt=i[23];
		Dect=i[22];
		Encspctrl=i[21];
		Enpc=i[20];
		S=i.read().range(19,17);//(i[19],i[18],i[17]);
		Enir=i[16];
		Selmux_1=i.read().range(15,13);
		MEM_Read=i[12];
		Selmux_2=i.read().range(11,10);
		Enmactimer=i[9];
		Txcaln=i[8];
		Txon=i[7];
		Txoncca=i[6];
		ackset=i[5];
		Txoff=i[4];
		flush_tx=i[3];
		Rxon=i[2];
		Rxoff=i[1];
		flush_rx=i[0];
	}
}
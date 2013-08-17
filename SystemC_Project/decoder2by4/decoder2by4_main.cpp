// Copyright 2003 Star Galaxy Publishing
// File: main_full_adder.cpp

#include "driver.h"
#include "monitor.h"
#include "decoder2by4.h"

int sc_main(int argc, char* argv[]) {
  sc_signal<bool> dc_en;
  sc_signal< sc_uint<2> > dc_sel;
  sc_signal< sc_uint<4> > dc_z;

  decoder2by4 dc1 ("decoder2by4");

  // Connect using positional association:
  dc1<< dc_en << dc_sel << dc_z;

  driver d1 ("GenerateWaveforms");

  // Connect using named association:
  d1.d_sel(dc_sel);
  //d1.d_b(dc_sel[1]);
  d1.d_en(dc_en);

  monitor mo1 ("MonitorWaveforms");
  mo1 << dc_en << dc_sel << dc_z;

  sc_start(100, SC_NS);
  system("pause");
  return(0);
}

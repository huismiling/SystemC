// Copyright 2003 Star Galaxy Publishing
// File: driver.cpp

#include "driver.h"

void driver::prc_driver () {
  sc_uint<3> pattern;

  pattern = 0;

  while (1) {
    d_sel = pattern;
    //d_sel[1] = pattern[1];
    d_en = pattern[2];

    wait (5, SC_NS);
    pattern++;
  }
}

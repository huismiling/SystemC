// Copyright 2003 Star Galaxy Publishing
// File: driver.h

#include "systemc.h"

SC_MODULE (driver) {
  sc_out<bool> d_en;
  sc_out< sc_uint<2> > d_sel;

  void prc_driver (); 

  SC_CTOR (driver) {
    SC_THREAD (prc_driver);
  }
};

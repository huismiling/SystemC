// Copyright 2003 Star Galaxy Publishing
// File: monitor.h

#include "systemc.h"

SC_MODULE (monitor) {
  sc_in<bool> m_en;
  sc_in< sc_uint<2> > m_sel;
  sc_in< sc_uint<4> > m_z;

  void prc_monitor ();

  SC_CTOR (monitor) {
    SC_METHOD (prc_monitor);
    sensitive  << m_z;
  }
};


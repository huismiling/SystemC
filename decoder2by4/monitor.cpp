// Copyright 2003 Star Galaxy Publishing
// File: monitor.cpp

#include "monitor.h"

void monitor::prc_monitor () {
  cout << "At time " << sc_time_stamp() << "::";

  cout << "(en, sel): ";

  cout << m_en << (sc_bv<2>) m_sel;

  cout << "  (sum, carry_out): " << (sc_bv<4>) m_z << endl;
}

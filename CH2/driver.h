// Copyright 2003 Star Galaxy Publishing
// File: driver.h

#include "systemc.h"

SC_MODULE (driver) {
	sc_out<bool> d_a, d_b, d_cin;

	void prc_driver (); 

	SC_CTOR (driver) {
		SC_THREAD (prc_driver);
	}
};

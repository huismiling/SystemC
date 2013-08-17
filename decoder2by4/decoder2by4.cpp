// Copyright 2003 Star Galaxy Publishing
// File: decoder2by4.cpp

#include "decoder2by4.h"

void decoder2by4::prc_decoder2by4() {
  if (enable) {
    switch (select.read()) {
      case 0: z = 0xE; break;
      case 1: z = 0xD; break;
      case 2: z = 0xB; break;
      case 3: z = 0x7; break;
    }
  }
  else
    z = 0xF;
}

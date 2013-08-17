// Copyright 2003 Star Galaxy Publishing
// File: half_adder.cpp              /* Line 1 */

#include "half_adder.h"              /* Line 2 */

void half_adder::prc_half_adder () { /* Line 3 */
  sum = a ^ b;                       /* Line 4 */
  carry = a & b;                     /* Line 5 */
}

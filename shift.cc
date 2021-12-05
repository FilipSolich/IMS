/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "config.hh"
#include "shift.hh"
#include <iostream>

Shift::Shift(Facility *slow_fac, Facility *fast_fac) :
	slow_fac(slow_fac), fast_fac(fast_fac)
{}

void Shift::Behavior()
{
	Seize(*fast_fac);

	while (true) {
		Wait(SLOW_SHIFT_DURATION);
		Seize(*slow_fac);
		Release(*fast_fac);
		Wait(FAST_SHIFT_DURATION);
		Seize(*fast_fac);
		Release(*slow_fac);
	}
}

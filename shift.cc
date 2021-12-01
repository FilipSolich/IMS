#include <simlib.h>

#include "shift.hh"


Shift::Shift(int slow_shift, int fast_shift, Facility *slow_fac, Facility *fast_fac) :
	slow_shift(slow_shift), fast_shift(fast_shift), slow_fac(slow_fac), fast_fac(fast_fac)
{
	Seize(*fast_fac);
}

void Shift::Behavior()
{
	while (true) {
		Wait(slow_shift);
		Seize(*slow_fac);
		Release(*fast_fac);
		Wait(fast_shift);
		Seize(*fast_fac);
		Release(*slow_fac);
	}
}

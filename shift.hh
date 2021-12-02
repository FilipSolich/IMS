/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef SHIFT_HH
#define SHIFT_HH

#include <simlib.h>


class Shift : public Process {
	Facility *slow_fac;
	Facility *fast_fac;

public:
	Shift(Facility *slow_fac, Facility *fast_fac);

	void Behavior();
};

#endif // SHIFT_HH

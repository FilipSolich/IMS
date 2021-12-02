/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef SHIFT_H
#define SHIFT_H

#include <simlib.h>


class Shift : public Process {
	bool state = 0;
	int slow_shift = 5; // TODO change
	int fast_shift = 3; // TODO change
	Facility *slow_fac = nullptr;
	Facility *fast_fac = nullptr;

public:
	Shift(int slow_shift, int fast_shift, Facility *slow_fac, Facility *fast_fac);

	void Behavior();
};

#endif // SHIFT_H

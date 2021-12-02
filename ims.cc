/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <iostream>
#include <stdlib.h>

#include "order_generators.hh"
#include "shift.hh"

const double T0 = 0.0;
const double T1 = 100.0; // TODO: change

const int SLOW_SHIFT_TIME = 3; // TODO: change
const int FAST_SHIFT_TIME = 3; // TODO: change

const int SLOW_SHIFT_GENERATE = 5; // TODO: change
const int FAST_SHIFT_GENERATE = 3; // TODO: change

const int CARS = 5;


int main() {
	Init(T0, T1);

	Store cars("Cars", CARS);

	Facility slow_facility("Slow facality");
	Facility fast_facility("Fast facality");

	(new Shift(SLOW_SHIFT_TIME, FAST_SHIFT_TIME, &slow_facility, &fast_facility))->Activate();

	(new Generators(SLOW_SHIFT_GENERATE, &slow_facility))->Activate();
	(new Generators(FAST_SHIFT_GENERATE, &fast_facility))->Activate();


	Run();

	// Generate stats

	return EXIT_SUCCESS;
}

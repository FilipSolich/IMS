/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <stdlib.h>

#include "config.hh"
#include "order_generators.hh"
#include "shift.hh"


int main() {
	Stat doba("doba");

	RandomSeed(time(NULL));

	Init(T0, T1);

	Store cars("Cars", CARS);

	Facility slow_facility("Slow facality");
	Facility fast_facility("Fast facality");

	(new Shift(&slow_facility, &fast_facility))->Activate();

	(new Generators(SLOW_SHIFT_GENERATE, &slow_facility, &cars))->Activate();
	//(new Generators(FAST_SHIFT_GENERATE, &fast_facility, &cars))->Activate();

	Run();

	doba.Output();
	// Generate stats

	return EXIT_SUCCESS;
}

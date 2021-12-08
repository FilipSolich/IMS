/*
 * ims.cc
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <iostream>

#include <stdlib.h>

#include "config.hh"
#include "order_generator.hh"
#include "shift.hh"


Stat delivery_time("Doba doručení objednávky");
Stat wait_for_car("Doba čekání na auto");

Histogram waiting_car("Histogram doby čekání na auto",0,1,10);

int wait_for_car_count = 0;

int main() {
	RandomSeed(time(NULL));

	Init(T0, T1);

	Store cars("Cars", CARS);

	Facility slow_facility("Slow facality");
	Facility fast_facility("Fast facality");
	
	(new Shift(&slow_facility, &fast_facility))->Activate();

	(new Generator(SLOW_SHIFT_GENERATE, &slow_facility, &cars))->Activate();
	(new Generator(FAST_SHIFT_GENERATE, &fast_facility, &cars))->Activate();

	Run();

	delivery_time.Output();
	wait_for_car.Output();

	std::cout << wait_for_car_count << " objednávek čekalo na auto." << std::endl;

	waiting_car.Output();

	SIMLIB_statistics.Output();

	return EXIT_SUCCESS;
}

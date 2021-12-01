/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <iostream>

#include <stdlib.h>

#include <simlib.h>


const double T0 = 0.0;
const double T1 = 100.0; // TODO: change

const int CARS = 5;

// car - process
// 2x generator objednvak: Event dostane v konstruktoru facality delku behu

int main() {
	Init(T0, T1);

	Facility slow_facility("");
	Facility fast_facility("");

	Run();

	// Generate stats

	return EXIT_SUCCESS;
}

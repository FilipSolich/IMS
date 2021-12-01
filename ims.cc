/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <iostream>
#include <stdlib.h>

#include "order_generators.h"

const double T0 = 0.0;
const double T1 = 100.0; // TODO: change

int main() {
	Init(T0, T1);
	Run();
	
	return EXIT_SUCCESS;
}
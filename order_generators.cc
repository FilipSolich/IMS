/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "order.hh"
#include "order_generators.hh"


Generators::Generators(int time, Facility *fac, Store *cars):
	time(time), fac(fac), cars(cars)
{};

void Generators::Behavior()
{
	(new Order(fac, cars))->Activate();

	Seize(*fac);
	Activate(Time + Exponential(time));
	Release(*fac);
};

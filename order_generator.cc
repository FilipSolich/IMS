/*
 * order_generator.cc
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "order.hh"
#include "order_generator.hh"


Generator::Generator(int time, Facility *fac, Store *cars):
	time(time), fac(fac), cars(cars)
{};

void Generator::Behavior()
{
	(new Order(fac, cars))->Activate();
	Activate(Time + Exponential(time));
};

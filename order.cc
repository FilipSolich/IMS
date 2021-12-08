/*
 * order.cc
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "car_returns.hh"
#include "config.hh"
#include "order.hh"
#include "stats.hh"


Order::Order(Facility *fac, Store *cars):
	fac(fac), cars(cars)
{};

void Order::Behavior()
{
	if (fac->Busy()) return;

	int sum = 0;

	if (cars->Full()) wait_for_car_count++;

	double wait_time = Time;
	Enter(*cars); //input one of car
	wait_time = Time - wait_time;
	waiting_car(wait_time);
	error:
	int x = Exponential(ORDER_DELIVERY_TIME);
	sum += x;
	Wait(x);

	if(Random() <= DELIVERY_FAILED)
		goto error;

	int y = Exponential(CUSTOMER_TAKE_ORDER);
	Wait(y); // taking order by customer
	sum += y;

	delivery_time(sum);
	wait_for_car(wait_time);
	
	(new CarGoBack(cars))->Activate();
}

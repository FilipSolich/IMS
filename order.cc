/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "car_go_back.hh"
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


	double wait_time = Time;
	Enter(*cars); //input one of car
	wait_time = Time - wait_time;

	chyba:
	int x = Exponential(ORDER_DELIVERY_TIME);
	sum += x;
	Wait(x);

	if(Random() <= DELIVERY_FAILED)
		goto chyba;

	int y = Exponential(CUSTOMER_TAKE_ORDER);
	Wait(y); // taking order by customer
	sum += y;

	delivery_time(sum);
	wait_for_car(wait_time);

	(new CarGoBack(cars))->Activate();
}

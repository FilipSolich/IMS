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
	double t_before;
	double t_after;

	t_before = Time;

	if (fac->Busy()) return;

	Enter(*cars); //input one of car
	chyba:
	Wait(Exponential(ORDER_DELIVERY_TIME));
	if(Random() <= DELIVERY_FAILED)
		goto chyba;
	
	Wait(Exponential(CUSTOMER_TAKE_ORDER)); // taking order by customer
	
	t_after = Time;

	doba(t_after - t_before);

	(new CarGoBack(cars))->Activate();
}

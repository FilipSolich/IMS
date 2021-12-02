/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <iostream>

#include <simlib.h>

#include "car_go_back.hh"
#include "config.hh"
#include "order.hh"

double t_delivery;
double t_wait;

Stat time_delivery("Doba doruceni objednavky");

Order::Order(Facility *fac, Store *cars):
	fac(fac), cars(cars)
{};

void Order::Behavior()
{
	t_delivery = 0;
	t_wait = 0;
	if (fac->Busy()) return;

	Enter(*cars); //input one of car
	chyba:
	t_delivery = Exponential(ORDER_DELIVERY_TIME);
	Wait(t_delivery);
	if(Random() <= DELIVERY_FAILED)
		goto chyba;
	
	t_wait = Exponential(CUSTOMER_TAKE_ORDER);
	doba(t_wait);
	Wait(t_wait); // taking order by customer

	t_delivery += t_wait;

	time_delivery(t_delivery);
	time_delivery.Output();
	(new CarGoBack(cars))->Activate();
}

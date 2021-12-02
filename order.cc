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

Order::Order(Facility *Fac, Store *cars):
	Fac(Fac), cars(cars)
{};

void Order::Behavior()
{
	t_delivery = 0;
	t_wait = 0;
	if (Fac->Busy()) return;

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

	(new CarGoBack(cars))->Activate();
}

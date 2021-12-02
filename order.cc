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


Order::Order(Facility *Fac, Store *cars):
	Fac(Fac), cars(cars)
{};

void Order::Behavior()
{
	Enter(*cars); //input one of car
	chyba:
	Wait(Exponential(ORDER_DELIVERY_TIME));
	if(Random() <= DELIVERY_FAILED)
		goto chyba;
	
	Wait(Exponential(CUSTOMER_TAKE_ORDER)); // taking order by customer
	(new CarGoBack(cars))->Activate();
}

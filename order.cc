/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "order.hh"


Order::Order(Facility *Fac, Store *cars):
	Fac(Fac),cars(cars)
{};

void Order::Behavior(){
	
	Enter(*cars); //input one of car
	chyba:
	Wait(Exponential(20)); //20min
	if( Random() <= 0.01 )	//1%
		goto chyba;
	
	Wait(Exponential(1)); // taking order by customer
	//order ended
	CarGo;
	(CarGo())->Activate();
}

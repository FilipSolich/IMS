/*
 * car_returns.cc
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "car_returns.hh"
#include "config.hh"


CarGoBack::CarGoBack(Store *cars):
	cars(cars)
{};

void CarGoBack::Behavior()
{
	Wait(CAR_RETURN_DURATION);
	Leave(*cars, 1);
}

/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include <simlib.h>

#include "car_go_back.hh"


CarGoBack::CarGoBack(Store *cars):
	cars(cars)
{};

void CarGoBack::Behavior()
{
	Wait(5);
	Leave(*cars, 1);
}
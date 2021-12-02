/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef ORDER_GENERATORS_HH
#define ORDER_GENERATORS_HH

#include <simlib.h>


class Generators : public Event {
	int time;
	Facility *fac;
	Store *cars;

public:
	Generators(int time, Facility *fac, Store *cars);

	void Behavior();
};

#endif // ORDER_GENERATORS_HH

/*
 * order_generator.hh
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef ORDER_GENERATOR_HH
#define ORDER_GENERATOR_HH

#include <simlib.h>


class Generator : public Event {
	int time;
	Facility *fac;
	Store *cars;

public:
	Generator(int time, Facility *fac, Store *cars);

	void Behavior();
};

#endif // ORDER_GENERATOR_HH

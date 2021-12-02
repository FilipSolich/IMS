/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef ORDER_GENERATORS_H_
#define ORDER_GENERATORS_H_

#include <simlib.h>


class Generators : public Process {
	int time;
	Facility *Fac;
	Store *cars;
public:
	Generators(int time, Facility *F, Store *cars);
	void Behavior();
};

#endif

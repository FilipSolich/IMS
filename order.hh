/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef ORDER_HH
#define ORDER_HH

#include <simlib.h>


class Order : public Process {
	Facility *Fac;
	Store *cars;

public:
	Order(Facility *Fac, Store *cars);

	void Behavior();
};

#endif // ORDER_HH

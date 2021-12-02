/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef ORDER_H
#define ORDER_H

#include <simlib.h>


class Order : public Process
{
	Facility *Fac;

public:
	Order(Facility *Fac);

	void Behavior();
};

#endif // ORDER_H

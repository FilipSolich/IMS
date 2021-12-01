/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */
#include <simlib.h>

#include "order_generators.h"


Generators::Generators(int time, Facility *F):
    time(time), Fac(F)
{};

void Generators::Behavior(){

    //Store++;
    Seize(*Fac);
    Activate(Time + Exponential(time));
    Release(*Fac);
};
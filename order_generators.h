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

class Generators : public Process
{
private:
    Facility *Fac;
    int time;
    Store *Stor;

public:
    Generators(int time,Facility *F, Store *Stor);
    void Behavior();
};

class Create_Ord : public Process
{
private:
    Facility *Fac;
    Store *Stor; //Todo
public:
    Create_Ord(Facility *Fac, Store *Stor);
    void Behavior();
};

#endif
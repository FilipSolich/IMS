/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#include "order_generators.h"
#include <simlib.h>

Generators::Generators(int time, Facility *F, Store *Stor): //Todo Store
    time(time), Fac(F), Stor(Stor){};

void Generators::Behavior(){

    //Store++;
    (new Create_Ord(Fac,Stor))->Activate();

    Seize(*Fac);   
    Activate(Time + Exponential(time));
    Release(*Fac);

};
Create_Ord::Create_Ord(Facility *Fac, Store *Stor):
    Fac(Fac), Stor(Stor){};

void Create_Ord::Behavior(){
    ; //kill process   
}
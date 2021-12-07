/*
 * car_returns.hh
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 */

#ifndef CAR_GO_BACK_HH
#define CAR_GO_BACK_HH

#include <simlib.h>


class CarGoBack : public Process {
	Store *cars;

public:
	CarGoBack(Store *cars);

	void Behavior();
};

#endif // CAR_GO_BACK_HH

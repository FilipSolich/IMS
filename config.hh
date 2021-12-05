/*
 * IMS
 *
 * Date:    30. 11. 2021
 * Authors: Filip Solich <xsolic00@stud.fit.vutbr.cz>
 *          Marek Sechra <xsechr00@stud.fit.vutbr.cz>
 *
 * All time constants are in minutes.
 */

#ifndef CONFIG_HH
#define CONFIG_HH

const int HOUR = 60; // 60m

const int T0 = 0;   // Simulation start
const int T1 = 480; // Simulation end

const int SLOW_SHIFT_DURATION = 3 * HOUR; // Slow shift length (default 3h)
const int FAST_SHIFT_DURATION = 4 * HOUR; // Fast shift length (default 4h)

const int SLOW_SHIFT_GENERATE = 5; // Slow shift generation new order (default 5m)
const int FAST_SHIFT_GENERATE = 3; // Fast shift generation new order (default 3m)

const int ORDER_DELIVERY_TIME = 20; // How long it takes order to delicver (default 20m)
const int CUSTOMER_TAKE_ORDER = 1;  // How long it takes customer to take order (default 1m)

const int CAR_RETURN_DURATION = 15; // How long it takes to car return for next order (default 15m)

const int CARS = 5; // Number of cars (default 5)

const double DELIVERY_FAILED = 0.01; // Delivery failed chance (default 1%)

#endif // CONFIG_HH

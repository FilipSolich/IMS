/*
 * config.hh
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

const double T0 = 0;         // Simulation start
const double T1 = 14 * HOUR; // Simulation end (default 14h)

const int SLOW_SHIFT_DURATION = 3 * HOUR; // Slow shift length (default 3h)
const int FAST_SHIFT_DURATION = 4 * HOUR; // Fast shift length (default 4h)

const int SLOW_SHIFT_GENERATE = 10; // Slow shift generation new order (default 5m)
const int FAST_SHIFT_GENERATE = 5; // Fast shift generation new order (default 3m)

const int ORDER_DELIVERY_TIME = 10; // How long it takes time delivery (default 10m)

const int CUSTOMER_TAKE_ORDER = 1;  // How long it takes customer to take order (default 1m)

const int CAR_RETURN_DURATION = 10; // How long it takes to car return for next order (default 10m)

const int CARS = 5; // Number of cars (default 5)

const double DELIVERY_FAILED = 0.01; // Delivery failed chance (default 1%)

#endif // CONFIG_HH

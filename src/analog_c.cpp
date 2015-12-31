/*
 * analog_c.cpp
 *
 *  Created on: Nov 3, 2015
 *      Author: Joshua Southerland
 */

#include "wallaby/analog.h"
#include "analog_p.hpp"

int analog(int port)
{
	return analog12(port);
}

int analog8(int port)
{
	return analog(port) >> 4;
}

int analog10(int port)
{
	return analog(port) >> 2;
}

int analog12(int port)
{
	return Private::Analog::instance()->value(static_cast<unsigned char>(port));
}

int analog_et(int port)
{
	return Private::Analog::instance()->value(static_cast<unsigned char>(port));
}

void set_analog_pullup(int port, int pullup)
{

}

int get_analog_pullup(int port)
{
	return 0;
}

#pragma once
/*
 * Location.h
 *
 *  Created on: Dec 9, 2014
 *      Author: Stephen Walentik
 */
#include "stdafx.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>

#ifndef SW_LOCATION_JDSU_H
#define SW_LOCATION_JDSU_H

using namespace std;

class Location{
public:
	string isle,
		section,
		hieght;

	friend ostream& operator<<(ostream& co, const Location dt);
};

#endif
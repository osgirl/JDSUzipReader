#pragma once
/*
 * Item.h
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
#include "Location.h"

#ifndef SW_ITEM_JDSU_H_
#define SW_ITEM_JDSU_H_

using namespace std;

class Item{
public:
	string itemName,
		quantity,
		itemNumber;

	Location local;

	double weight;

	Item();
	Item(string, string, string, double);//itemName, Quan, ItemNumber, Local, weight
	Item(string, string, string, Location, double);//itemName, Quan, ItemNumber, Local, weight
};

#endif
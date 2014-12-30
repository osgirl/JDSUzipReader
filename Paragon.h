#pragma once
/*
 * Paragon.h
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
#include "Customer.h"
#include "Item.h"
//#include "Location.h"

#ifndef SW_PARAGON_JDSU_H
#define SW_PARAGON_JDSU_H

using namespace std;

class Order{
public:
	vector<Customer> custList;
	vector<Item> itemList;

	Order();
	Customer	getCustomer(string, string, string);//first name, last name, address1
	bool		searchCustList(string, string, string);//first name, last name, address1
	bool		searchCustList(string, string);//first name, last name
	bool		searchCustList(string);//address1
	bool		searchItemList(string);//item name
	bool		searchCustItemList(Customer, string);
	void		printCustList();
	double		getWeightTotal(Customer);

	void		printOrders();
	bool		addCustomer(Customer);
	bool		addItem(Item);
	bool		addCustItem(Customer&, Item);
	void		modifyShipRecord();
};

void fieldString(string, string, Order&);
void fileParser(string, ifstream&, Order&);

#endif

#pragma once
/*
 * Customer.h
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
//#include "Paragon.h"
#include "Item.h"

#ifndef SW_CUSTOMER_JDSU_H
#define SW_CUSTOMER_JDSU_H

using namespace std;

class Customer{
public:
	Customer();
	void	setCustomerName(string,string);//First and last name
	void	setCustomerAddress(string,string);//address1 and address2
	void	setCustomerLocation(string, string, string, string);//city, state, zip, country
	void	setCustomerCompany(string);
	void	setCustomerEmail(string);
	double	getWeightTotal();
	bool	addCustItem(Item, Customer&);

	friend	ostream& operator<<(ostream& co, const Customer);

	string	firstname,
			lastname,
			company,
			address,
			address2,
			city,
			state,
			zip,
			country,
			email,
			orderNumber;

	vector<Item> custOrder;
};

#endif
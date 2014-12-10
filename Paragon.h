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

#ifndef SW_PARAGON_JDSU_H
#define SW_PARAGON_JDSU_H

using namespace std;

void fileParser(string, ifstream&);

class Customer{
public:
	Customer();
	void setCustomerName(string,string);//First and last name
	void setCustomerAddress(string,string);//address1 and address2
	void setCustomerLocation(string, string, string, string);//city, state, zip, country
	void setCustomerCompany(string);
	void setCustomerEmail(string);

	string firstname,
		lastname,
		company,
		address,
		address2,
		city,
		state,
		zip,
		country,
		email;
};

void fieldString(string, Customer);

#endif

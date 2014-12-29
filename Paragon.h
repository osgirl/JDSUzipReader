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

#ifndef SW_PARAGON_JDSU_H
#define SW_PARAGON_JDSU_H

using namespace std;

class Location{
public:
	string isle,
		section,
		hieght;

	friend ostream& operator<<(ostream& co, const Location dt);
};

class Item{
public:
	string itemName,
		quantity;
	Location local;
	int weight;
};

class Customer{
public:
	Customer();
	void setCustomerName(string,string);//First and last name
	void setCustomerAddress(string,string);//address1 and address2
	void setCustomerLocation(string, string, string, string);//city, state, zip, country
	void setCustomerCompany(string);
	void setCustomerEmail(string);
	void printCustomer();

	friend ostream& operator<<(ostream& co, const Customer);

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

	vector<Item> custOrder;
};

class Order{
public:
	vector<Customer> custList;
	vector<Item> itemList;

	Order();
	bool searchCustList(string, string, string);//first name, last name, address1
	bool searchCustList(string, string);//first name, last name
	bool searchCustList(string);//address1
	bool searchItemList(string);//item name
	void printCustList();

	void printOrders();
	void addCustomer(Customer);
	void addItem(Item);
	void modifyShipRecord();
};

void fieldString(string, string, Order&);
void fileParser(string, ifstream&, Order&);

#endif

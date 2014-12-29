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
		quantity,
		itemNumber;
	Location local;
	double weight;

	Item();
	Item(string, string, string, double);//itemName,Quan, ItemNumber, Local, weight
};

class Customer{
public:
	Customer();
	void	setCustomerName(string,string);//First and last name
	void	setCustomerAddress(string,string);//address1 and address2
	void	setCustomerLocation(string, string, string, string);//city, state, zip, country
	void	setCustomerCompany(string);
	void	setCustomerEmail(string);
	double	getWeightTotal();

	friend	ostream& operator<<(ostream& co, const Customer);

	string firstname,
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

class Order{
public:
	vector<Customer> custList;
	vector<Item> itemList;

	Order();
	Customer	getCustomer(string, string, string);
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

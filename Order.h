//header
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef MES_PARAGON_ORDER_H_
#define MES_PARAGON_ORDER_H_

class Order{

public: 
	// Opens shipper.csv
	void OpenShipper();
	
	// Variables
	int filenum;	   // Steve called this quantity
	string filename;   
	vector<string> filenamesList;

	////////////////////////////////////////////////////
	// From the board.
	vector<string> Customers;
	vector<string> itemList;

	int printOrders();       // return 0 if error
	int addCust();           //return 0 if error
	int addItem();           // uses Cust
	int modifyShipRecord();  //uses additem
	
};
#endif
// JDSUzipReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Paragon.h"
#include "Customer.h"
#include "Item.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Shipper.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Order orders;

	OpenShipper(orders);

	fileDriver(orders);

	orders.printOrders();
	orders.printPickOrders();
	orders.modifyShipRecord();

	return 0;
}


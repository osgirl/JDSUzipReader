#include "stdafx.h"
#include "Paragon.h"
#include <sstream>

using namespace std;

void fileDriver(Order& orders){
	ifstream myfile("spreadsheet.csv");

	fileParser("spreadsheet.csv",myfile,orders);
}

void fileParser(string filename, ifstream &paraFile, Order &paraOrder){
	string inLine, line;
	int count = 0,
		countLine = 0;

	if (paraFile.is_open())
	{
		while (getline(paraFile,inLine))
		{
			int lsize = inLine.size(), at = 1;
			for(int i = 1; i < lsize-1; ++i) if(inLine[i-1] == 00) inLine[at++] = inLine[i];
			inLine.resize(at);

			fieldString(filename, inLine, paraOrder);

			++count;
		}
		paraFile.close();
	}
}

//Needs to be fed the file not the string of the line
void fieldString(string paraName, string paraLine, Order &paraOrder){
	int done=0,
		commaCount=0;
	string temp = "";

	Customer paraCust;

	Item testItem("123","250","Baseball", 2); //ItemNumber, Quan, Name, weight

	for(int i=0; i<paraLine.length()-1 && done != 11 && paraLine[i]!='\n'; ++i){
		if(paraLine[i]!=','){
			temp = temp + paraLine[i];
		}
		else{ 
			++commaCount;
		
			if (commaCount==1 && temp != "UserFormSubmit"){
				paraCust.orderNumber = temp;
				done=1;
				temp = "";
			} else if(commaCount==3 && done == 1 && temp != "First Name"){
				paraCust.firstname = temp;
				done=2;
				temp = "";
			} else if(commaCount==4 && done == 2){
				paraCust.lastname = temp;
				done=3;
				temp = "";
			} else if(commaCount==5 && done == 3){
				paraCust.company = temp;
				done=4;
				temp = "";
			} else if(commaCount==6 && done == 4){
				paraCust.address = temp;
				done=5;
				temp = "";
			} else if(commaCount==7 && done == 5){
				paraCust.address2 = temp;
				done=6;
				temp = "";
			} else if(commaCount==8 && done == 6){
				paraCust.city = temp;
				done=7;
				temp = "";
			} else if(commaCount==9 && done == 7){
				paraCust.state = temp;
				done=8;
				temp = "";
			} else if(commaCount==10 && done == 8){
				paraCust.zip = temp;
				done=9;
				temp = "";
			} else if(commaCount==11 && done == 9){
				paraCust.country = temp;
				done=10;
				temp = "";
			} else if(commaCount==12 && done == 10){
				paraCust.email = temp;
				done=11;
				temp = "";
				if(!paraOrder.addCustomer(paraCust)) paraOrder.addCustItem(paraOrder.getCustomer(paraCust.firstname, paraCust.lastname, paraCust.address), testItem);
				else paraOrder.addCustItem(paraOrder.getCustomer(paraCust.firstname, paraCust.lastname, paraCust.address), testItem);
			} else if(paraLine[i]==',') temp = "";
		}
		if(paraLine[i]=='\n'){
			done = 11;
			paraOrder.addCustomer(paraCust);
			commaCount = 0;
		}
	}
}



//=================================================================
//
//  Class: Order
//
//=================================================================
Order::Order(){
	custList.reserve(100);
	itemList.reserve(13);
}
Customer& Order::getCustomer(string parafname, string paralname, string paraAddress){
	for(int i=0; i < custList.size(); ++i){
		if(custList[i].firstname == parafname && custList[i].lastname == paralname && custList[i].address == paraAddress){
			return custList[i];
		}
	}
}
bool Order::searchCustList(string parafname, string paralname, string paraAddress){
	for(int i=0; i < custList.size(); ++i){
		if(custList[i].firstname == parafname && custList[i].lastname == paralname && custList[i].address == paraAddress)
			return true;
		else if (custList[i].firstname == "")
			return true;
	}
	return false;
}
bool Order::searchCustList(string paraAddress){
	for(int i=0; i < custList.size(); ++i){
		if(custList[i].address == paraAddress)
			return true;
		else if (custList[i].firstname == "")
			return true;
	}
	return false;
}
bool Order::searchCustList(string parafname, string paralname){
	for(int i=0; i < custList.size(); ++i){
		if(custList[i].firstname == parafname && custList[i].lastname == paralname)
			return true;
		else if (custList[i].firstname == "")
			return false;
	}
	
	return false;
}
bool Order::addCustomer(Customer paraCust){
	if(!searchCustList(paraCust.firstname, paraCust.lastname, paraCust.address)){
		custList.push_back(paraCust);
		return true;
	}
	return false;
}
bool Order::addItem(Item paraItem){
	if(!searchItemList(paraItem.itemName)){
		itemList.push_back(paraItem);
		return true;
	}
	return false;
}
bool Order::addCustItem(Customer& paraCust, Item paraItem){
	paraCust.addCustItem(paraItem);
	return true;
}
void Order::printCustList(){
	cout << "Printing Customer List\n";
	cout << custList[0].firstname << " " << custList[0].lastname << "\n";
}
void Order::printOrders(){
	ofstream printFile;
	printFile.open("orders.csv");
	printFile << "JDSU Order Report\n\n";

	printFile << "Number of Customers: " << custList.size() << '\n';
	printFile << "Number of Total Items: \n";// << itemList.size() << '\n\n\n';

	for(int i=0; i<custList.size(); ++i){
		printFile << "Order Reference Number: " << custList[i].orderNumber << '\n';
		printFile << custList[i].firstname << " " << custList[i].lastname << '\n';
		printFile << custList[i].address << '\n' << custList[i].address2 << "\n\n";
		printFile << "Item List\n" << "Item name,Item Number, BIN Location\n";

		for(int j=0; j<custList[i].custOrder.size();++j){
			printFile << custList[i].custOrder[j].itemName << ',' << custList[i].custOrder[j].itemNumber << ',' << custList[i].custOrder[j].local << '\n';
		}
		printFile << "\n\n\n\n";
	}

	printFile.close();
}
//Pay extra for thrid party shipping. 
//Not in the scope of the overview
void Order::modifyShipRecord(){
	ofstream shipFile;
	shipFile.open("batch_shipment.csv");
	shipFile << "COMPANYNAME,ADDRESS,CITY,ST,POSTALCODE,FNAME,LNAME,PHONENUMBER,REFTWO,REFONE,TPAcct,PACKWEIGHT,CID,UPSSERVICE,COUNTRY,BILLTRANS,PACKTYPE,PROFILE,TPName,TPAddress1,TPCity,TPState,TPCountry,TPZIP\n";
	
	for(int i=0; i<custList.size() ;++i){
		shipFile << custList[i].company << "," << custList[i].address << " " << custList[i].address2 << ","
			<< custList[i].city << ',' << custList[i].state << ',' << custList[i].zip << ',' << custList[i].firstname << ','
			<< custList[i].lastname << ',' << ',' << "REFTWO" << ',' << "REFONE" << ',' << "TPAcct" << ',' << getWeightTotal(custList[i]) << ','
			<< ',' << "GROUND" << ',' << custList[i].country << ',' << "SHIPPER" << ',' << "CP" << ',' 
			<< "PROFILE" << ",,,,\n";
	}
	
	

	shipFile.close();
}
bool Order::searchItemList(string paraItemName){
	for(int i=0; i < itemList.size(); ++i){
		if(itemList[i].itemName == paraItemName)
			return true;
	}
	return false;
}
bool Order::searchCustItemList(Customer paraCust, string paraItemName){
	for(int i=0; i < paraCust.custOrder.size(); ++i){
		if(paraCust.custOrder[i].itemName == paraItemName)
			return true;
	}
	return false;
}
double Order::getWeightTotal(Customer paraCust){
	return paraCust.getWeightTotal();
}
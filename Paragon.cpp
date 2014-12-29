#include "stdafx.h"
#include "Paragon.h"
#include <sstream>

using namespace std;

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

			//if(count>=7){
				fieldString(filename, inLine, paraOrder);
			//}

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
			} else if(commaCount==6 && done ==4){
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
				paraOrder.addCustomer(paraCust);
				cout << paraCust;
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
//  Class: Customer
//
//=================================================================
Customer::Customer(){

}
void Customer::setCustomerName(string fname,string lname){
	firstname = fname;
	lastname = lname;
}
void Customer::setCustomerAddress(string address1,string address22){
	address = address1;
	address2 = address22;
}
void Customer::setCustomerLocation(string paraCity, string paraState, string paraZip, string paraCountry){
	city = paraCity;
	state = paraState;
	zip = paraZip;
	country = paraCountry;
}
void Customer::setCustomerCompany(string paraCompany){
	company = paraCompany;
}
void Customer::setCustomerEmail(string paraEmail){
	email = paraEmail;
}
ostream& operator<<(ostream& co, const Customer paraCust)
{
    co << "//=== Printing Customer ========================================= \n"
		<< "Customer Name: " << paraCust.firstname << " " << paraCust.lastname << "\n"
		<< "Customer Company: " << paraCust.company << "\n"
		<< "Customer Address: " << paraCust.address + " " + paraCust.city + ", " + paraCust.state + " " + paraCust.country + " " + paraCust.zip + "\n"; 
    return co;
}
double Customer::getWeightTotal(){
	int sum =0;
	for(int i=0; i<custOrder.size(); ++i){
		sum = custOrder[i].weight;
	}
	return sum;
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
void Order::printCustList(){
	cout << "Printing Customer List\n";
	cout << custList[0].firstname << " " << custList[0].lastname << "\n";
	//cout << custList.at(0).firstname << " " << custList.at(0).lastname << "\n";
}
void Order::printOrders(){
	ofstream printFile;
	printFile.open("orders.csv");
	printFile << "";
	printFile.close();
}
void Order::addCustomer(Customer paraCust){
	if(!searchCustList(paraCust.firstname, paraCust.lastname, paraCust.address)){
		custList.push_back(paraCust);
	}
}
void Order::addItem(Item paraItem){
	if(!searchItemList(paraItem.itemName)){
		itemList.push_back(paraItem);
	}
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
	for(int i=0; i < custList.size(); ++i){
		if(itemList.at(i).itemName == paraItemName)
			return true;
	}
	return false;
}
double Order::getWeightTotal(Customer paraCust){
	return paraCust.getWeightTotal();
}

//=================================================================
//
//  Class: Location
//
//=================================================================

ostream& operator<<(ostream& co, const Location dt)
{
    co << dt.isle << dt.section << '/' << dt.hieght;
    return co;
}
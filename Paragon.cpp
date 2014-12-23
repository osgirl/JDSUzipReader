#include "stdafx.h"
#include "Paragon.h"
#include <sstream>

using namespace std;

void fileParser(string filename, ifstream &paraFile, Order paraOrder){
	string inLine, line;
	int count = 0,
		countLine = 0;

	if (paraFile.is_open())
	{
		while (getline(paraFile,inLine))
		{
			int lsize = inLine.size(), at = 1;
			for(int i = 1; i < lsize-1; ++i) if(inLine[i-1] == 00) inLine[at++] = inLine[i];
			// if there is no space behind it, skip it, it is a broken space itself
			inLine.resize(at);
			
			if (count>=5) 
			cout << inLine << '\n' << count << "\n";
			
			//for(int i=0; i < 2; ++i){
			//if (count>=5) 
				fieldString(inLine, paraOrder.custList[0]);
			//}

			++count;
			//++countLine;

			//if(count>=5){
			//	cout << count << "\n\n\n";
				//count=0;
				//++countLine;
			//}
		}
		paraFile.close();
	}
}

//Needs to be fed the file not the string of the line
void fieldString(string paraLine, Customer &paraCust){
	int done=0,
		commaCount=0;
	string temp = "";

	cout << "Debug for the fieldString function: \n"
		<< "paraLine: " << paraLine << "\n"
		<< "paraLine is " << paraLine.length() << " long\n";

	for(int i=0; i<paraLine.length()-1 && done == 10 && paraLine[i]=='\n'; ++i){
		cout << "paraLine[" << i << "]: " << paraLine[i] << "\n";
		if(paraLine[i]!=',') temp = temp + paraLine[i];
		else{ 
			++commaCount;

			cout << i;
		
			if(commaCount==3 && done == 0){
				paraCust.firstname = temp;
				done=1;
				temp = "";
				cout << "commaCount is 3\n";
			} else if(commaCount==4 && done == 1){
				paraCust.lastname = temp;
				done=2;
				temp = "";
				cout << "commaCount is 4\n";
			} else if(commaCount==5 && done == 2){
				paraCust.company = temp;
				done=3;
				temp = "";
				cout << "commaCount is 5\n";
			} else if(commaCount==6 && done == 3){
				paraCust.address = temp;
				done=4;
				temp = "";
				cout << "commaCount is 6\n";
			} else if(commaCount==7 && done == 4){
				paraCust.address2 = temp;
				done=5;
				temp = "";
				cout << "commaCount is 7\n";
			} else if(commaCount==8 && done == 5){
				paraCust.city = temp;
				done=6;
				temp = "";
				cout << "commaCount is 8\n";
			} else if(commaCount==9 && done == 6){
				paraCust.state = temp;
				done=7;
				temp = "";
				cout << "commaCount is 9\n";
			} else if(commaCount==10 && done == 7){
				paraCust.zip = temp;
				done=8;
				temp = "";
				cout << "commaCount is 10\n";
			} else if(commaCount==11 && done == 8){
				paraCust.country = temp;
				done=9;
				temp = "";
				cout << "commaCount is 11\n";
			} else if(commaCount==12 && done == 9){
				paraCust.email = temp;
				done=10;
				temp = "";
				cout << "commaCount is 12\n";
				paraCust.printCustomer();
			} else if(paraLine[i]==',') temp = "";
		}
		if(paraLine[i]=='\n') done = 10;
	}
}

//=================================================================
//
//Class: Customer
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
void Customer::printCustomer(){
	cout << "//=== Printing Customer ========================================= \n"
		<< "Customer Name: " << firstname << " " << lastname << "\n";
}

//=================================================================
//
//Class: Order
//
//=================================================================
Order::Order(){

}
Customer Order::searchCustList(string parafname, string paralname, string paraAddress){
	for(int i=0; i < 1000; ++i){
		if(custList[i].firstname == parafname && custList[i].lastname == paralname && custList[i].address == paraAddress)
			return custList[i];
		else if (custList[i].firstname == "")
			return custList[i];
	}
	
	return custList[999];
}
Customer Order::searchCustList(string paraAddress){
	for(int i=0; i < 1000; ++i){
		if(custList[i].address == paraAddress)
			return custList[i];
		else if (custList[i].firstname == "")
			return custList[i];
	}
	
	return custList[999];
}
Customer Order::searchCustList(string parafname, string paralname){
	for(int i=0; i < 1000; ++i){
		if(custList[i].firstname == parafname && custList[i].lastname == paralname)
			return custList[i];
		else if (custList[i].firstname == "")
			return custList[i];
	}
	
	return custList[999];
}
void Order::printCustList(){
	cout << "Printing Customer List\n";
	cout << custList[0].firstname << " " << custList[0].lastname << "\n";
}

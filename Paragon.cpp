#include "stdafx.h"
#include "Paragon.h"
#include <sstream>

using namespace std;

void fileParser(string filename, ifstream &paraFile){
	string inLine, line;
	int count = 0,
		countLine = 0;

	if (paraFile.is_open())
	{

		while ( getline(paraFile,inLine))
		{
			int lsize = inLine.size(), at = 1;
			for(int i = 1; i < lsize-1; ++i) if(inLine[i-1] == 00) inLine[at++] = inLine[i];
			// if there is no space behind it, skip it, it is a broken space itself
			inLine.resize(at);
			
			if (count>=5) 
			cout << inLine << '\n' << count << "\n";
			
			++count;
			//++countLine;

			//if(count>=5){
				//cout << count << "\n\n\n";
				//count=0;
				//++countLine;
			//}
		}
		paraFile.close();
	}
}
void fieldString(string paraLine, Customer paraCust){
	int done=0,
		commaCount=0;
	string temp;
	for(int i=0; i<paraLine.size() || done == 10; ++i){
		temp += paraLine[i];
		if(commaCount==3){
			paraCust.firstname = temp;
			done=1;
		} else if(commaCount==4){
			paraCust.lastname = temp;
			done=2;
		} else if(commaCount==5){
			paraCust.company = temp;
			done=3;
		} else if(commaCount==6){
			paraCust.address = temp;
			done=4;
		} else if(commaCount==7){
			paraCust.address2 = temp;
			done=5;
		} else if(commaCount==8){
			paraCust.city = temp;
			done=6;
		} else if(commaCount==8){
			paraCust.state = temp;
			done=7;
		} else if(commaCount==9){
			paraCust.zip = temp;
			done=8;
		} else if(commaCount==10){
			paraCust.country = temp;
			done=9;
		} else if(commaCount==11){
			paraCust.email = temp;
			done=10;
		} else temp = "";

	}
}

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
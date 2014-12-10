#include "stdafx.h"
#include "Paragon.h"
#include <sstream>

using namespace std;

void fileParser(string filename, wifstream &paraFile){
	wstring inLine, line;
	int count = 0;

	if (paraFile.is_open())
	{

		while ( getline(paraFile,inLine, ','))
		{
		//	int lsize = inLine.size(), at = 1;
		//	for(int i = 1; i < lsize-1; ++i) if(inLine[i-1] == ' ') inLine[at++] = inLine[i];
			// if there is no space behind it, skip it, it is a broken space itself
		//	inLine.resize(at);
			
			if (count>=7) 
			cout << "After: " << inLine << '\n';
			++count;
		}
		paraFile.close();
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
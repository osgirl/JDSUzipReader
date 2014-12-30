#include "stdafx.h"
#include "Customer.h"
#include <sstream>

//=================================================================
//
//  Class: Customer 
//
//=================================================================
Customer::Customer(){
	custOrder.reserve(13);
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
bool Customer::addCustItem(Item paraItem){
	custOrder.push_back(paraItem);
	return true;
}
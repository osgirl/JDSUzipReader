//cpp

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Paragon.h"
using namespace std;


double string_to_double( const std::string& weight )
{
   std::istringstream i(weight);
   double x;
   if (!(i >> x))
   {
	return 0;
   }
   return x;
}


//fills up items
void OpenShipper(Order& orders)
{
	string item_Name,
		shipperQuantity,
		itemNumber,
		bin,
		weight,
		DataInFile;
	int commaCount = 0;
	Item MikesItem(item_Name, shipperQuantity, itemNumber, 0.0);
	ifstream myFile("shipper.csv");
	if( myFile.is_open() ){
		getline( myFile, DataInFile );
		while( !myFile.eof() ){
			string temp = "";
			//cout << "DataInFile: \n" << DataInFile << '\n'; (NOT NECESSARY - says Mike)
			if(DataInFile == "item,quantity,itemNumber,location,weight"){
				DataInFile = "";
			}
			for(int i=0; i < DataInFile.length() && DataInFile[i] != '\n' && commaCount != 6; ++i){
				if( DataInFile[i]!=',' ){
				temp = temp + DataInFile[i];
				} else { 
					++commaCount;
					if (commaCount==1){
						MikesItem.itemName = temp;
						temp = "";
					} else if(commaCount==2){
						MikesItem.quantity = temp;
						temp = "";
					} else if(commaCount==3){
						MikesItem.itemNumber = temp;
						temp = "";
						if(MikesItem.itemName == "item")orders.addItem(MikesItem);
						cout << MikesItem << '\n'; 
							//<< "CommaCount: " << commaCount;
					} else if(commaCount==4){
						Location MikesLocation(temp);
						MikesItem.local = MikesLocation;
						temp = "";
					} else if(commaCount==5){
						MikesItem.weight = string_to_double(temp);
						temp = "";
						//if(MikesItem.itemName == "item")orders.addItem(MikesItem);
						//cout << MikesItem.weight << '\n'; 
							//<< "CommaCount: " << commaCount;
					} 
				}
			}
			getline(myFile, DataInFile);
			commaCount=0;
		}
	}
	myFile.close();
}
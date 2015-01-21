//cpp

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include "Paragon.h"
using namespace std;

//fills up items
void OpenShipper(Order& orders)
{
	double totalWeight = 0;

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
			getline(myFile, DataInFile);
			string temp = "";
			if(DataInFile == "item,quantity,itemNumber,location,weight,"){
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
					} else if(commaCount==4){
						Location MikesLocation(temp);
						MikesItem.local = MikesLocation;
						temp = "";
					} else {				
						double convertWeight, convertQuantity, subWeight;
						
						stringstream cw, cq;
						cq << MikesItem.quantity;
						cq >> convertQuantity;
						cw << temp;
						cw >> convertWeight;
						MikesItem.weight = convertWeight;

						subWeight = convertQuantity * convertWeight;
						totalWeight += subWeight;

						cout << "weight: " << convertWeight  
							<< " quantity: " << convertQuantity << " "
							<< "subW: " << subWeight << " "
							<< "tw: " << totalWeight <<endl;
						
						temp = "";
						if(MikesItem.itemName != "item")orders.addItem(MikesItem);
					} 
				}
			}
			commaCount=0;
		}
	}
	cout << "rounded up weight: " << ceil(totalWeight) << endl;
	system("pause");
	myFile.close();
}
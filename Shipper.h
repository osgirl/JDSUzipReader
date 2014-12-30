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

void OpenShipper()
{
	// Variable Definitions
	string item_Name,
		shipperQuantity,
		itemNumber,
		bin,
			//MikesIsle,
			//MikesSection,
			//MikesHeight,
		weight,
		DataInFile;
	int commaCount = 0;
	
	Item MikesItem(item_Name, shipperQuantity, itemNumber, 0.0);
	//Location MikesLocation(MikesIsle, MikesSection, MikesHeight);
	Location MikesLocation;


	ifstream myFile("shipper.csv");

	if(myFile.is_open())
	{
		// for debuging
		//cout << "File successfully opened\n";
		while(!myFile.eof())
		{
			//Reads the shipper file one line at a time.
			getline(myFile, DataInFile);
			// Skips the first line of the shipper file.
			if(DataInFile == "item,quantity,location,weight")
			{
				// for debugging
				//cout << "in the special condiction\n";
				continue;
			}
			//This is a test to just get the filenames and open them.
			// Might put it into it's own function
			//cout <<"line size "<< DataInFile.length() << endl;
			
			//Parse the line and stop at the first comma.
			for(int i = 0; i < DataInFile.length(); i++)
			{
				if(commaCount == 0 && DataInFile[i] != ',')
				{ 
					//cout << "comma Count (0) \n";
					//cout << DataInFile[i];
					//create name substr
						item_Name = DataInFile[i];
						//debug
						//cout << itemName;
						MikesItem.itemName = item_Name;
						cout << MikesItem.itemName; 
				}

				if(commaCount == 1 && DataInFile[i] != ',')
				{
					//cout << "comma Count (1) \n";
					//cout << DataInFile[i];
					//create quantity substr
						shipperQuantity = DataInFile[i];
						//debug
						//cout << shipperQuantity;
						MikesItem.quantity = shipperQuantity;
						cout << MikesItem.quantity;
				}

				if(commaCount == 2 && DataInFile[i] != ',')
				{
					//cout << "comma Count (2) \n";
					//cout << DataInFile[i];
					//create bin or location substr
						bin = DataInFile[i];
						//cout << bin;
						Location(bin);
				}

				if(commaCount == 3 && DataInFile[i] != ',' && DataInFile[i] != '\n' )
				{
					weight = DataInFile[i];
					cout << weight;
					MikesItem.weight = string_to_double( weight );
				}

				if(DataInFile[i] == ',')
				{
					//cout << " /commaCount = " << commaCount << endl;
					++commaCount;
					cout << endl;
					//cout << "commaCount: " << commaCount << endl;
					//for debugging
					//cout << "comma position = " << i << endl;
				}

				else if(commaCount < 3)
				{
					commaCount = 0;
				}

			}//end of For Loop
			std::cout << endl;		
			
		}//end of while loop
		
		/*
					//creates a substring location
					for(int l = 0; l < commaPos; ++l)
					{
						bin = DataInFile.substr(i+1, 3);
					}

		*/
			
			//for debugging
			//cout << "getline is done\n";
			//cout << DataInFile;
			//cout << itemName; 
				//<< " " << itemName.size();
				//<< " " << quantity << " "  << bin;
			//cout << endl;

	}//end of if statement

	else if(myFile.fail())
	{
		std::cout << "Failed to open.\n";
		system("pause");
		exit(1);
	}

	myFile.close();
}//End of function0
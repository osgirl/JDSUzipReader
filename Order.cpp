//cpp

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Order.h"
#include "Paragon.h"
using namespace std;

void Order::OpenShipper()
{
	string itemName, quantity, bin;
	string DataInFile, substring;
	ifstream myFile("shipper.csv");
	int commaPos;
	
	if(myFile.is_open())
	{
		// for debuging
		//cout << "File successfully opened\n";
		
		while(!myFile.eof())
		{
			//Reads the shipper file one line at a time.
			getline(myFile, DataInFile);
			// Skips the first line of the shipper file.
			if(DataInFile == "item,quantity,bin")
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
				// For Debugging
				//cout << "in the string at: " <<  DataInFile.at(i) << endl;
				if(DataInFile.at(i) == ',')
				{	
					//debugging
					//cout << "in the special condiction for the comma\n";
					//cout << DataInFile.at(i) << endl;
					commaPos = i;
					//cout << "commaPos = " << commaPos << endl;
					//cout << "i = "<< i << endl;
					
					// creates a substring with just the filename.
					for(int j = 0; j < commaPos; ++j)
					{
						//cout << DataInFile.at(j);
						itemName = DataInFile.substr(0,i-2);
					}

					// creates a substring quantity
					for(int k =0; k < commaPos; ++k)
					{
						quantity = DataInFile.substr(i-1, 1);
					}

					//creates a substring location
					for(int l = 0; l < commaPos; ++l)
					{
						bin = DataInFile.substr(i+1, 3);
					}
					
				}
			}
			
			////////////////////////////////////////////////////////

			//for debugging
			//cout << "getline is done\n";
			//cout << DataInFile;
			cout << itemName << " " << quantity << " "  << bin;

			cout << endl;
		}
	}

	else if(myFile.fail())
	{
		cout << "Failed to open.\n";
		system("pause");
		exit(1);
	}
	// Old code
	/*
	// Input files names into a vector of strings
	for(int i = 0; i < 13; ++i)
	{
		cin >> filename;
		filenamesList.push_back(filename);
	}

	// Open the filenames that are stored into
	// the vector and pass them to the fileParser.
	for(int i = 0; i < 13; ++i)
	{
		filenamesList[i] = filename;
		ifstream myFile(filename);
		
		if(myFile.is_open())
		{
			while( getline(myFile, dataInFile, ',') )
			{
				fileParser(dataInFile, myFile);
			}
		}
		else
			cout << "Unable to open " << filenamesList[i];
	}
	*/
}

int Order::printOrders()
{
	return 0;
}

int Order::addCust()
{
	return 0;
}
int Order::addItem()
{
	return 0;
}
int modifyShipRecord()
{
	return 0;
}
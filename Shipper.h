//cpp

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Paragon.h"
using namespace std;

void OpenShipper()
{
	string itemName, quantity, bin;
	string DataInFile, substring;
	ifstream myFile("shipper.csv");
	int commaCount = 0;
	
	if(myFile.is_open())
	{
		// for debuging
		//cout << "File successfully opened\n";
		while(!myFile.eof())
		{
			//Reads the shipper file one line at a time.
			getline(myFile, DataInFile);
			// Skips the first line of the shipper file.
			if(DataInFile == "item,quantity,bin,weight")
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
					cout << DataInFile[i];
					//create name substr
				}

				if(commaCount == 1 && DataInFile[i] != ',')
				{
					cout << DataInFile[i];
					//create quantity substr
				}

				if(commaCount == 2 && DataInFile[i] != ',')
				{
					cout << DataInFile[i];
					//create bin or location substr
				}

				if(DataInFile[i] == ',')
				{
					commaCount++;
					cout << endl;
					//cout << "comma position = " << i << endl;
				}

				else
					commaCount = 0;
			

			}//end of For Loop

			// best choice so far.
			std::cout << itemName;
				//<< bin;
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
}//End of function





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


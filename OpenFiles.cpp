//cpp

#include "stdafx.h"
#include "OpenFiles.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void OpenFiles::OpenSpreadSheet()
{
	ifstream inStream("spreadsheet.csv");
	inStream.open("spreadsheet.csv");

	if(inStream.is_open())
		cout << "Sucessfully Opened the spreadsheet.\n";

	else if(inStream.fail())
	{	
		cout << "Failed to open the spreadsheet.\n";
		system("pause");
		exit(0);
	}

}

void OpenFiles::CloseSpreadSheet()
{

	ifstream inStream("spreadsheet.csv");
	
	if(inStream.is_open())
	{
		inStream.close();
		cout << "Sucessfully closed the spreadsheet.\n";
	}
}

void OpenFiles::set_filename(string f){
	filename = f;
	
	/*
	//Debugging
	cout << "f = " << f << endl;
	cout << "filename = " << filename << endl;
	system("pause");
	*/
}

void OpenFiles::openfiles()
{
	int filecount;

	//Loops until the enter key is pressed.
	while(!cin.get()=='\n')
	{
		getline(cin, filename);
		filecount++;
	}


	cout << filename << endl;
	
	ofstream myfileout(filename);
	ifstream myfile (filename);

	for(int i = 0; i < filecount; i++)
	{	
		myfileout.open(filename);
	}
  
	if (myfile.is_open())
	{
		while ( getline (myfile, filename) )
		{
			cout << filename << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file\n";

}
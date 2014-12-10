//cpp

#include "stdafx.h"
#include "OpenFiles.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void OpenFiles::OpenSpreedSheet()
{
	ofstream myfileout("spreadsheet.zip");
	myfileout.open("spreadsheet.zip");
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
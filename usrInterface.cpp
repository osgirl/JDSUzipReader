#include "stdafx.h"
#include "usrInterface.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void usrInterface::DisplayInterface()
{
	char input;
	cout << "Do you have multiple spreadsheets? (y/n)";
	cin >> input;

	if(input == 'Y' || input == 'y')
	{	
		cout << "Selected multiple spreadsheets.\n";
	
	}

	else if(input == 'N' || input == 'n')
	{
		cout << "Selected single spreadsheet.\n";
		OpenSpreadSheet();
	}

	else
	{
		cout << "User entered wrong input.\n";
		cout << "Please enter y or n.\n";
		system("pause");
		exit(0);
	}
}
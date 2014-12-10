// JDSUzipReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "Paragon.h"
#include "OpenFiles.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	OpenFiles OF;
	OF.OpenSpreadSheet();
	OF.CloseSpreadSheet();


	//ifstream myfile("spreadsheet.csv");

	//string inLine;

	//fileParser("spreadsheet.csv",myfile);

	system("pause");
	return 0;
}


// JDSUzipReader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string inLine;

	getline(cin, inLine);
	cout << inLine << endl;
	
	 ifstream myfile (inLine);
  if (myfile.is_open())
  {
    while ( getline (myfile, inLine) )
    {
      cout << inLine << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file\n"; 

	system("pause");
	return 0;
}


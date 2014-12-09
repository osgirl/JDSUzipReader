#include "stdafx.h"
#include "Paragon.h"

using namespace std;

void fileParser(string filename, ifstream &paraFile){
	string inLine;

	if (paraFile.is_open())
	{
		while ( getline(paraFile,inLine) )
		{
			cout << inLine << '\n';
		}
		paraFile.close();
	}
}
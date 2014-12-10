#include "stdafx.h"
#include "Paragon.h"

using namespace std;

void fileParser(string filename, ifstream &paraFile){
	string inLine;
	int count = 0;

	if (paraFile.is_open())
	{

		while ( getline(paraFile,inLine))
		{
			if (count==7) cout << inLine << '\n';
			++count;
		}
		paraFile.close();
	}
}
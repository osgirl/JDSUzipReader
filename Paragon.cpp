#include "Paragon.h"

using namespace std;

void fileParser(string filename, ifstream paraFile){
	string inLine;

	while(paraFile.eof()){
		getline(cin, inLine);

		cout << inLine << "\n";
	}

}
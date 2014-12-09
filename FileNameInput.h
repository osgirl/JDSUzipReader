#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef MES_PARAGON_FILENAMEINPUT_H_
#define MES_PARAGON_FILENAMEINPUT_H_

class FileNameInput{

public: 
	//FileNameInput() {string filename = ""};
	//~FileNameInput();
	void openzip();
	void openfiles();

private:
	string filename;
};
#endif
//header

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef MES_PARAGON_OPENFILES_H_
#define MES_PARAGON_OPENFILES_H_

class OpenFiles{

public: 
	
	void OpenSpreadSheet();
	void CloseSpreadSheet();
	void openfiles();

private:
	string filename;
};
#endif
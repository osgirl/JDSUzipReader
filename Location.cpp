#include "stdafx.h"
#include "Location.h"
#include <sstream>

//=================================================================
//
//  Class: Location
//
//=================================================================

ostream& operator<<(ostream& co, const Location dt)
{
    co << dt.isle << dt.section << '/' << dt.height;
    return co;
}
Location::Location(string paraIsle,string paraSection,string paraHeight){
	isle = paraIsle;
	section = paraSection;
	height = paraHeight;
}
Location::Location(){
	isle = "A";
	section = "1";
	height = "1";
}
Location::Location(string paraRawInput){
	isle = paraRawInput[0];
	section = paraRawInput[1];
	height = paraRawInput[3];
}
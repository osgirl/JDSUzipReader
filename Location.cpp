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
    co << dt.isle << dt.section << '/' << dt.hieght;
    return co;
}
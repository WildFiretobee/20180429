 ///
 /// @file    TemplateSingleton.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-22 12:20:25
 ///

#include "Mylogger.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename Type>
class Point
{
public:

	Point(Type arg)
	: _ix(arg)
	, _iy(0)
	{
		LogDebug("Point(arg)");
	}
	
	Point(Type ix,Type iy)
	: _ix(ix)
	, _iy(iy)
	{
		LogDebug("Point(arg,arg)");
	}

private:
	Type _ix;
	Type _iy;
};



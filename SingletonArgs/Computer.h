 ///
 /// @file    TemplateSingleton.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-22 12:20:25
 ///

#include "Mylogger.h"
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Computer
{
public:

	Computer()
	{
		LogDebug("Computer()");
	}
	
	Computer(const char * ix,int iy)
	: _ix(new char[strlen(ix)+1]())
	, _iy(iy)
	{
		strcpy(_ix,ix);
		LogDebug("Computer(char*,int)");
	}

private:
	char * _ix;
	int _iy;
};



 ///
 /// @file    Singleton.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-21 16:52:54
 ///
#include "Point2.h" 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;

template<typename Type>
class Singleton
{
public:
	template<typename... Args>
	static Type * getInstance(Args&&... args)
	{
		if(_pInstance == NULL)
		{
			_pInstance=new Type(std::forward<Args>(args)...);
		}
		return _pInstance;
	}

	static void destory()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl;}

private:
	static Type * _pInstance;
};

template<class T> T * Singleton<T>::_pInstance = NULL;

int main(void)
{
	Point *p1 = Singleton<Point>::getInstance(1,2);
	Point *p2 = Singleton<Point>::getInstance(1,2);

	Computer *p3 = Singleton<Computer>::getInstance("xiaomi",6666);
	Computer *p4 = Singleton<Computer>::getInstance("xiaomi",6666);	

	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	cout << "p3 = " << p3 << endl;
	cout << "p4 = " << p4 << endl;

	Singleton<Point>::destory();
	Singleton<Computer>::destory();
	return 0;
}


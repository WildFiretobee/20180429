 ///
 /// @file    AutoReleaseSingleton2.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-19 21:39:42
 ///

#include "Point2.h"
#include <stdlib.h>
#include <pthread.h>

#include <iostream>
using std::cout;
using std::endl;


template <typename Type>
class Singleton
{
public:
	template<typename... Args>	
	static Type * getInstance(Args&&... args)
	{
		pthread_once(&_once, init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Type(std::forward<Args>(args)...);
		::atexit(destory);
	}

	static void destory()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){ cout << "Singleton()" << endl; }
	~Singleton(){ cout << "~Singleton()" << endl; }

	static Type * _pInstance;
	static pthread_once_t _once;
};

template<typename Type>
Type * Singleton<Type>::_pInstance = NULL;//饿汉模式，懒汉模式（懒加载）

template<typename Type>
pthread_once_t Singleton<Type>::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Point * p1 = Singleton<Point>::getInstance(1,2);
	Point * p2 = Singleton<Point>::getInstance(1,2);

	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	return 0;
}

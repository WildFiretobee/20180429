 ///
 /// @file    for_earch.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-26 19:23:26
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::for_each;

void test()
{
	cout << "test()" << endl;
}

typedef void(*Function)(void);

int test1()
{
	Function f = test;
	f();
	return 0;
}

void print(int number)
{
	cout << number << " ";
}

void test2()
{
	int a = 10;
	int b = 100;
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	for_each(numbers.begin(), numbers.end(), print);
	cout << endl;
	//lambda表达式代表的是匿名函数
	for_each(numbers.begin(), numbers.end(), [&](int number){
		cout << number << " a = " << a << " b = " << b << endl;
	});
	cout << endl;
	cout << " a = " << a << endl;
	cout << " b = " << b << endl;
}

void test3()
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	//std::replace(numbers.begin(), numbers.end(), 3, 7)
	std::less<int> lt;
	//std::replace_if(numbers.begin(), numbers.end(), std::bind1st(lt,3), 7); // lt(3, x) 函数适配（绑定）器
	std::replace_if(numbers.begin(), numbers.end(), std::bind2nd(lt,3), 7); // lt(x, 3) 函数适配（绑定）器
	
	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;
	//std::replace_if();
}

int main()
{
	test();
	cout << endl;
	test1();
	cout << endl;
	test2();
	cout << endl;
	test3();
	cout << endl;

	return 0;
}











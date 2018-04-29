 ///
 /// @file    remove.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-26 19:38:00
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::remove;

int test()
{
	vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	numbers[3] = numbers[6] = numbers[8] =66;
	
	// earse-remove 惯用法
	numbers.erase(remove(numbers.begin(), numbers.end(), 66),
			numbers.end());
	copy(numbers.begin(), numbers.end(),
			std::ostream_iterator<int>(cout, ","));
	cout << endl;
#if 0
	//在容器遍历的过程中，不要做删除或者添加元素的操作
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if(*it == 66)
		{
			numbers.earse(it);
		}
	}

#endif

	return 0;
}

void test1()
{	
	vector<int> numbers{1, 2};
	bool flag = true;
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		//遍历容器的过程中，添加元素可能会产生的异常情况
		cout << "numbers' size = " << numbers.size() << endl;
		cout << "numbers' capacity = " << numbers.capacity() << endl;
		cout << "*it = " << *it << endl;
		if(flag)
		{
			numbers.push_back(3);//底层发生了动态扩容，原来的迭代器失效了
			flag = false;
		}
	}
}

int main()
{
	test();
	test1();

	return 0;
}













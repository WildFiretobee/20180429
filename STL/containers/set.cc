 ///
 /// @file    set.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-24 19:45:27
 ///
 
#include <iostream>
#include <math.h>
#include <set>
#include <utility>
#include <string>
using std::cout;
using std::endl;
using std::set;
using std::string;

template <typename Contaniner>
void printContaniner(const Contaniner & contaniner)
{
	typename Contaniner::const_iterator cit = contaniner.begin();
	while(cit != contaniner.end())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

int test0(void)
{
	int arr[10] = {3, 2, 4, 5, 3, 1, 2, 6, 7, 5};
	//set之中不能存放关键字相同的元素
	//默认情况下以升序的方式进行排列，因为默认情况下指定了 operator< 的比较方式
	
	//set<int> setInt;
	set<int> setInt(arr, arr + 10);
	cout << "set'size() = " << setInt.size() << endl;
	printContaniner(setInt);

	//setInt[1];//set 并不支持下标访问运算符
	
	//set的底层实现是红黑树 --> 动态平衡二叉树 --> 原因：加快元素查找的效率 O(logN) --> 二分查找
	
	//set<int>::iterator sit = setInt.begin();
	//*sit = 10;// error, 添加到set中的元素不能修改
	
	return 0;
}

int test1(void)
{
	int arr[10] = {3, 2, 4, 5, 3, 1, 2, 6, 7, 5};
	//set之中不能存放关键字相同的元素
	//set可以指定排序方式
	set<int, std::greater<int>> setInt(arr, arr + 10);
	cout << "set'size() = " << setInt.size() << endl;
	printContaniner(setInt);

	//setInt[1];//set 并不支持下标访问运算符

	//pair
	std::pair<string, int> t("hello",55);
	cout << t.first << "-->" << t.second << endl;

	//insert 1 方法
	//std::pair<set<int, std::greater<int>>::iterator, bool>
	cout << endl << "insert test:" << endl;
	auto ret = setInt.insert(8);
	if(ret.second)
		cout << "element insert success" << endl;
	else
		cout << "element insert failure" << endl;
	printContaniner(setInt);

	//insert 2
	auto sit = setInt.begin();
	++sit;
	auto rit = setInt.insert(sit, 0);
	cout << "*rit = " << *rit << endl;
	printContaniner(setInt);

	//insert 3
	int arr2[3] = {1, 10, 20};
	setInt.insert(arr2, arr2 + 3);
	printContaniner(setInt);

	//erase
	cout << "erase test:" << endl;
	setInt.erase(rit);
	printContaniner(setInt);

	sit = setInt.begin();
	++sit; ++sit; ++sit;
	setInt.erase(setInt.begin(), sit);
	printContaniner(setInt);

	//clear
	setInt.clear();
	printContaniner(setInt);

	return 0;
}

class Point
{
public:
	Point(int ix = 0,int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}
	
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{	cout << "Point(const Point &)" << endl;		}

	void set(int ix,int iy)
	{
		_ix = ix;
		_iy = iy;
	}

	double length() const
	{
		return sqrt(pow(_ix, 2) + pow(_iy, 2));
	}

	~Point()
	{	cout << "~Point()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
	friend bool operator<(const Point & lhs, const Point & rhs);
	friend bool operator>(const Point & lhs, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.length() < rhs.length();
}

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.length() > rhs.length();
}

void test2()
{
	set<Point, std::greater<Point>> points{
		Point(1, 2),
		Point(3, 4),
		Point(5, 6),
		Point(1, 2)
	};

	printContaniner(points);
}

int main()
{
	test1();
	test2();
	return 0;
}





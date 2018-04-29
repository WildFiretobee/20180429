 ///
 /// @file    map.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-24 20:22:06
 ///
#include <map>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;

template <typename Container>
void printContainer(const Container & container)
{
	for(auto & elem : container)
	{
		cout << elem.first << "-->" << elem.second << endl;
	}
}

void test0(void){
	//map 之中不能存放关键字相同的元素，该元素是一个pair类型
	//默认情况下按关键字的升序方式进行排列
	map<string, int> mapStrInt{
		pair<string, int>("hello",66),
		std::make_pair("world",77),
		std::make_pair("ni",88),
		std::make_pair("hao",99),
		std::make_pair("world",77)
	};

	printContainer(mapStrInt);

	//map 提供了下标访问运算符
	cout << mapStrInt["hello"] << endl;// 时间复杂度为O(logN)
	//下标访问运算符执行时，若关键字存在，直接返回对应的value;
	//若关键字不存在，则会根据关键字创建一个元素（pair）
	cout << "search  element" << mapStrInt["world"] << endl;
	printContainer(mapStrInt);

	//只做查找操作
	//count
	cout << endl;
	int ret = mapStrInt.count("king");
	cout << "ret = " << ret << endl;
	if(ret)
		cout << "key: element is exist" << endl;
	else
		cout << "key: element is not exist" << endl;

	//find
	auto it = mapStrInt.find("king");
	if(it != mapStrInt.end()){
		cout << "key: element is exist" << endl;
		cout << it->first << "-->" << it->second << endl;
	}else
		cout << "key: element is not exist" << endl;
}

void test1(){
	//map 之中不能存放关键字相同的元素
	//默认情况下按关键字的升序方式进行排序
	map<string, int, std::greater<string>> mapStrInt{
		pair<string, int>("hello",66),
		std::make_pair("world",77),
		std::make_pair("ni",88),
		std::make_pair("hao",99),
		std::make_pair("world",77)
	};

	printContainer(mapStrInt);

	//查找元素
	cout << "lower_bound/upper_bound test: " << endl;
	auto lit = mapStrInt.lower_bound("world");
	auto uit = mapStrInt.upper_bound("world");
	cout << lit->first << "-->" << lit->second << endl;
	cout << uit->first << "-->" << uit->second << endl;
	
	//添加元素
	cout << "insert test" << endl;
	// std::pair<map<string, int, std::greater<string>>::iterator, bool> ret;
	auto ret = mapStrInt.insert(std::make_pair("king",520));
	if(ret.second)
	{
		cout << "insert success" << endl;
		cout << ret.first->first << "-->" << ret.first->second << endl;
	}
}	

int main()
{
	test0();
//	test1();

	return 0;
}




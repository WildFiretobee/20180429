 ///
 /// @file    multimap.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-24 20:22:06
 ///
#include <map>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::multimap;
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
	//multimap 之中能存放关键字相同的元素，该元素是一个pair类型
	//默认情况下按关键字的升序方式进行排列
	multimap<string, int> multimapStrInt{
		pair<string, int>("hello",66),
		std::make_pair("world",77),
		std::make_pair("ni",88),
		std::make_pair("hao",99),
		std::make_pair("world",77)
	};

	printContainer(multimapStrInt);

	//multimap 不提供了下标访问运算符
	//cout << multimapStrInt["hello"] << endl;

	//只做查找操作
	//count
	cout << endl;
	int ret = multimapStrInt.count("king");
	cout << "ret = " << ret << endl;
	if(ret)
		cout << "key: element is exist" << endl;
	else
		cout << "key: element is not exist" << endl;

	//find
	auto it = multimapStrInt.find("king");
	if(it != multimapStrInt.end()){
		cout << "key: element is exist" << endl;
		cout << it->first << "-->" << it->second << endl;
	}else
		cout << "key: element is not exist" << endl;
}

void test1(){
	//multimap 之中能存放关键字相同的元素
	//默认情况下按关键字的升序方式进行排序
	multimap<string, int, std::greater<string>> multimapStrInt{
		pair<string, int>("hello",66),
		std::make_pair("world",77),
		std::make_pair("ni",88),
		std::make_pair("hao",99),
		std::make_pair("world",77)
	};

	printContainer(multimapStrInt);

	cout << "lower_bound/upper_bound test: " << endl;
	auto lit = multimapStrInt.lower_bound("world");
	auto uit = multimapStrInt.upper_bound("world");
	cout << lit->first << "-->" << lit->second << endl;
	cout << uit->first << "-->" << uit->second << endl;
	
	
	cout << "equal_range test:" << endl;
	auto ret = multimapStrInt.equal_range("king");
	for(;ret.first != ret.second; ++ret.first)
	{
		cout << ret.first->first << "-->" << ret.first->second << endl;
	}
}	

int main()
{
	test0();
	test1();

	return 0;
}




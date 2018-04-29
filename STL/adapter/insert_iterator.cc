 ///
 /// @file    insert_iterator.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-26 19:01:57
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::ostream_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;

int main()
{
	vector<int> numbers1{1, 2, 3};
	list<int> numbers2{4, 5, 6};
	// 调用push_back方法，适用的容器有vector,list,deque
	copy(numbers2.begin(), numbers2.end(),
			back_insert_iterator<vector<int>>(numbers1));
	cout << "vector:";
	copy(numbers1.begin(),numbers1.end(),
			ostream_iterator<int>(cout, ","));
	cout << endl;

	// 调用push_front 方法，适用的容器有list,deque
	copy(numbers1.begin(), numbers1.end(),
			front_insert_iterator<list<int>>(numbers2));
	cout << "list:";
	copy(numbers2.begin(), numbers2.end(),
			ostream_iterator<int>(cout, ","));
	cout << endl;

	auto it = numbers2.begin();
	++it; ++it; ++it;
	//调用insert方法，适用所有的容器
	copy(numbers1.begin(), numbers1.end(),
			insert_iterator<list<int>>(numbers2, it));
	cout << endl;

	set<int> numbers3;
	auto sit = numbers3.begin();
	//调用insert方法，适用于除std::array/std::forward_list以外的所有容器
	copy(numbers1.begin(), numbers1.end(),
			insert_iterator<set<int>>(numbers3, sit));
	cout << "set:";
	copy(numbers3.begin(), numbers3.end(),
			ostream_iterator<int>(cout, ","));
	cout << endl;

	return 0;

}




















 ///
 /// @file    binary_search.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-26 19:49:40
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;


int main()
{
	vector<int> numbers{1, 2, 3, 4, 5, 1, 6, 3, 7, 4, 5, 9};
	std::sort(numbers.begin(), numbers.end());
	std::copy(numbers.begin(),numbers.end(),
				std::ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << std::boolalpha << std::binary_search(numbers.begin(),
			numbers.end(),10) << endl;
	cout << std::boolalpha << std::binary_search(numbers.begin(),
			numbers.end(),5) << endl << endl;

	auto it1 = std::lower_bound(numbers.begin(), numbers.end(), 2);
	auto it2 = std::upper_bound(numbers.begin(), numbers.end(), 2);
	while(it1 != it2)
	{
		cout << *it1 << ",";
		++it1;
	}
	cout << endl;

	auto ret = std::equal_range(numbers.begin(), numbers.end(), 2);
	while(ret.first != ret.second)
	{
		cout << *ret.first << ",";
		++ret.first;
	}
	cout << endl;

	return 0;
}















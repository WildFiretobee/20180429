 ///
 /// @file    set_intersection.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-26 20:00:58
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> numbers1{1, 2, 3, 4, 5, 6};
	vector<int> numbers2{3, 5, 7, 9};

	std::set_intersection(
			numbers1.begin(), numbers1.end(),
			numbers2.begin(), numbers2.end(),
			std::ostream_iterator<int>(cout, " "));
	cout << endl;
	
	std::set_difference(
			numbers1.begin(), numbers1.end(),
			numbers2.begin(), numbers2.end(),
			std::ostream_iterator<int>(cout, " "));
	cout << endl;		

	return 0;
}















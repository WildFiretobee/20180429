 ///
 /// @file    stack.cc
 /// @author  WildFiretobee(Danderous@email.com)
 /// @date    2018-04-24 20:14:34
 ///
 
#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

int main()
{
	stack<int, vector<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}

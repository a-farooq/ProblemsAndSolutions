/****
Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 10^5

Example:
Input:
3
{([])}
()
([]

Output:
balanced
balanced
not balanced
  ****/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string st;
	    cin >> st;
	    stack<char> stk;
	    bool balanced=true;
	    for(auto ch : st) {
	        if(ch=='{' || ch=='(' || ch=='[') {
	            stk.push(ch);
	        }
	        else {
	            if(stk.empty()) {
	                balanced=false;
	                break;
	            }

	            if(ch==')') {
	                if(stk.top()!= '(') {
	                    //cout << "not balanced" << endl;
	                    balanced=false;
	                    break;
	                }
	                else stk.pop();
	            }
	            else if(ch=='}') {
	                if(stk.top()!= '{') {
	                    //cout << "not balanced" << endl;
	                    balanced=false;
	                    break;
	                }
	                else stk.pop();
	            }
	            if(ch==']') {

	                if(stk.top()!= '[') {
	                    //cout << "not balanced" << endl;
	                    balanced=false;
	                    break;
	                }
	                else stk.pop();
	            }
	        }
	    }
	    if(!stk.empty()) balanced=false;
	    cout << (balanced?"balanced":"not balanced") << endl;
	}
	return 0;
}

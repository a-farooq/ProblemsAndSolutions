/****
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid substring.

NOTE: Length of smallest the valid substring ( ) is 2.

 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a string S consisting only of ( and ).


Output

Print out the length of the longest valid substring.

Constraints
1 <= T <= 100
0 <   S  <= 110

 

Examples 

Input
4
(()(
()()((
((()()())))
()(())(

Output
2
4
10
6

Explanation:
Test Case 1: (()(
The longest valid substring is "()". Length = 2
Test Case 2: ()()((
The longest valid substring is "()()". Length = 4
Test Case 3: ((()()())))
The longest valid substring is "((()()()))". Length = 10
​Test Case 4: ()(())(
The longest valid substring is "()(())". Length = 6


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
	    stack<int> stk;
	    string st;
	    cin >> st;
	    int maxi=0;
	    for(int i=0; i<st.length(); i++)
	    {
	        char ch=st[i];
	        if(ch=='(') //push -1 for left brace
	            stk.push(-1);
	        else {

	            int k=0;

	            //if top > 0, it is nested case, pop till left brace
	            //and add to count
	            while(!stk.empty() && stk.top() > 0) {
	                k+= stk.top();
	                stk.pop();
	            }
	            //if top is -1, its a pair, pop it and push 2
	            if(!stk.empty() && stk.top()<0) {
	                stk.pop();
	                stk.push(k+2);
	            }
	            //if empty, calculate max
	            if(stk.empty()) {
	                maxi = max(maxi, k);
	            }
	        }
	    }
	    int k=0;
	    while(!stk.empty()) {
	        if(stk.top()>0) {
	            k+=stk.top();
	            maxi = max(maxi, k);
	        }
	        else {
	            maxi = max(maxi, k);
	            k=0;
	        }
	        stk.pop();
	    }
	    cout << maxi << endl;
	}
	return 0;
}

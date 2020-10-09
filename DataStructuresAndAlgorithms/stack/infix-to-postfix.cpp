/****
Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Input:
The first line of input contains an integer T denoting the number of test cases. The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 10^3

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/
  ****/

#include <iostream>
#include <stack>
using namespace std;

bool isOp(char ch)
{
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-'||ch=='('||ch==')')
        return true;
    return false;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string st, out;
	    stack<char> stk;
	    cin >> st;
	    for(auto ch:st)
	    {
	        if(!isOp(ch))
	            out += ch;
	        else {
	            if(stk.empty())
	                stk.push(ch);
	            else if(ch==')') {
	                while(!stk.empty() && stk.top()!='(') {
	                    out += stk.top();
	                    stk.pop();
	                }
	                stk.pop();
	            }
	            else {
    	            switch(ch)
    	            {
						//highest precedence
    	                case '(':
    	                case '^':
    	                    stk.push(ch);
    	                    break;
						//second highest precedence
						//pop all higher or equal precedence
    	                case '*':
    	                case '/':
    	                    while(!stk.empty() &&
    	                    stk.top()=='^'||stk.top()==ch) {
    	                        out += stk.top();
    	                        stk.pop();
    	                    }
    	                    stk.push(ch);
    	                    break;
						//lowest precedence
						//pop all except '('
    	                case '+':
    	                case '-':
    	                    while(!stk.empty() &&
    	                    //(stk.top()=='^' || stk.top()=='*'||stk.top()=='/')
    	                    stk.top()!='('
    	                    )
    	                    {
    	                        out += stk.top();
    	                        stk.pop();
    	                    }
    	                    stk.push(ch);
    	                    break;
    	                default: break;
    	            }
	            }
	        }
	    }
	    while(!stk.empty()) {
	        out += stk.top();
	        stk.pop();
	    }
	    cout << out << endl;
	}
	return 0;
}

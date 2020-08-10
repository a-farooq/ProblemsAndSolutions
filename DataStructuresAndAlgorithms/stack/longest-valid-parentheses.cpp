/**************
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

Input:
First line contains number of test cases T.  Each test case have one line string S of character '(' and ')' of length  N.

Constraints:
1 <= T <= 500
1 <= N <= 105

Example:
Input:
2
((()
)()())

Output:
2
4

Explanation:
Testcase 1: Longest valid balanced parantheses is () and its length is 2.

*************/
#include <iostream>
#include <stack>
using namespace std;
stack <int> stk;

int main()
{
    int t;
    string sp;
    cin >> t;
    while(t--)
    {
        cin >> sp;
        int i = 0;
        int sum = 0, max = 0;
        
        while(!stk.empty()) stk.pop();
        
        stk.push(-1);
        while(i < sp.length())
        {
            char par = sp[i];
            if(par=='(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if(stk.empty())
                    stk.push(i);
                else {
                    int j = stk.top();
                    max = max < i-j ? i-j : max;
                }    
            }
            ++i;
            //cout << max << endl;
        }
        cout << max << endl;
    }
}

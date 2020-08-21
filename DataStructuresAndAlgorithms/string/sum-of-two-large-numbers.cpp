/****
Given two non-negative numbers X and Y. The task is calculate the sum of X and Y. If the number of digits in sum (X+Y) are equal to the number of digits in X, then print sum, else print X.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two numbers X and Y.

Output:
For each test case, print the required answer.

Constraints:
1<=T<=500
1<=|Digits in X,Y|<=100

Example:
Input:
2
25 23
100 1000

Output:
48
100

EXPLANATION:

TestCase2: Since 100+1000=1100 which has 4 digits while 100(i.e X) has only 3 digits.Hence our answer will be 100 as per the prob statement.
  ****/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	string s1, s2, sum;
	cin >> t;
	while(t--)
	{
	    cin >> s1 >> s2;
	    sum = "";
	    int carry = 0;
	    for(int i = s1.length()-1, j = s2.length()-1; i >= 0 || j >= 0 || carry; i--, j--)
	    {
	        int d1 = 0, d2 = 0;
	        if(i >= 0) d1 = s1[i]-'0';
	        if(j >= 0) d2 = s2[j]-'0';

	        int d = d1+d2+carry;

	        carry = d/10;
	        sum += to_string(d%10);
	    }
	    if(sum.length() > s1.length()) cout << s1 << endl;
	    else cout << string(sum.rbegin(), sum.rend()) << endl;
	    //else cout << reverse(sum.begin(), sum.end()) << endl;

	}
	return 0;
}

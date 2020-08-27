/****
Given a positive number N. The task is to round N to nearest multiple of 10. Number can be so big and can contains 1000 of digits.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a positive number N.

Output:
For each test case, print the nearest multiple of 10 in new line.

Constraints:
1 <= T <= 100
1 <= |Number length| <= 1000

Example:
Input:
3
15
29
996
Output:
10
30
1000
  ****/

#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;

	    int len = str.length();

	    char last = str[len-1];
	    str[len-1] = '0';

	    if(last > '5') {
	        int i = len-2;
	        int carry = 1;
	        while(carry && i >= 0) {
	            if(str[i] < '9') {
	                str[i] += carry;
	                carry = 0;
	            }
	            else str[i] = '0';
	            i--;
	        }
	        if(carry) str = "1"+ str;
	    }
	    cout << str << endl;
	}
	return 0;
}

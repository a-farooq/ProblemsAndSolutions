/****
Given two numbers. Add the numbers and find the count of carries in their addition.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two integer N and M as input.

Output:
For each test case, In new line print the count of carries.

Constraints:
1<=T<=1000
1<=N,M<=10^18

Example:
Input:
2
345 234
2345 535

Output:
0
1
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long a, b;
	    cin >> a >> b;
	    int c = 0, cnt = 0;
	    while(a || b) {
	        long x = a%10;
	        a= a/10;
	        long y = b%10;
	        b= b/10;
	        int d = x+y+c;
	        c = d/10;
	        if(c) cnt++;
	    }
	    cout << cnt << endl;
	}
	return 0;
}

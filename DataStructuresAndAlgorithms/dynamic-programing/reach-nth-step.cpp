/****
There are N points on the road ,you can step ahead by 1 or 2 . Find the number of ways you can reach at point N. For example:  for N=4 we have 5 possible ways [1,1,1,1]  [1,1,2]  [1,2,1]  [2,1,1]  [2 2].

Input:
The first line of input contains an integer T denoting the number of test cases. Next line of each input contains a single integer N.

Output:
For each testcase, in a new line, print the number of ways.

Constraints:
1<=T<=100
1<=N<=90

Example:
Input:
2
4
5

Output:
5
8
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    long pp = 0;
	    long pre = 1;
	    long res = 1;
	    cin >> n;
	    for(int i=1; i<=n; i++) {
	        res = pp+pre;
	        pp = pre;
	        pre = res;
	    }
	    cout << res << endl;
	}
	return 0;
}

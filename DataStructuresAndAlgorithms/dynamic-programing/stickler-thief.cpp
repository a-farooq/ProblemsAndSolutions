/****
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each test case contains an integer n which denotes the number of houses. Next line contains space separated numbers denoting the amount of money in each house.

Output:
For each testcase, in a newline, print an integer which denotes the maximum amount he can take home.

Constraints:
1 <= T <= 200
1 <= n <= 10^4
1 <= a[i] <= 10^4

Example:
Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, sum;
	    cin >> n;
	    int a[n];
	    for (int i=0; i<n; i++) cin >> a[i];

	    if(n==0) sum=0;
	    else if(n==1) sum=a[0];
	    else if(n==2) sum=max(a[0], a[1]);
	    else {
	        /*
	        //using extra space O(n)
	        int dp[n];
	        dp[0]=a[0];
	        dp[1]=max(a[0], a[1]);

	        for(int i=2; i<n; i++) {
	            dp[i]=max(a[i]+dp[i-2], dp[i-1]);
	        }
	        sum = dp[n-1];*/

	        //using constant space O(1)
	        int prev = max(a[0], a[1]);
	        int pp = a[0];
	        int maxi;
	        for(int i=2; i<n; i++) {
	            maxi = max(a[i]+pp, prev);
	            pp = prev;
	            prev = maxi;
	        }
	        sum = maxi;
	    }
	    cout << sum << endl;
	}
	return 0;
}

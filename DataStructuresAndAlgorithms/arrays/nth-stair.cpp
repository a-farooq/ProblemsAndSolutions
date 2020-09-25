/****
There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, an integer N will be given.

Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair. Answer your output % 10^9+7.

Constraints:
1<=T<=10^5
1<=N<=10^5

Example:
Input:
3
4
10
24
Output:
5
89
75025


  ****/

#include <iostream>
using namespace std;
#define MAX 100005
long long dp[MAX];
int mod=1000000007;

int main() {
	//code

	int t;
	cin >> t;
	dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=MAX; i++) {
	   dp[i]=(dp[i-1]+dp[i-2])%mod;
	}

	while(t--)
	{
	    int n;
	    cin >> n;

	    cout << dp[n] << endl;
	}
	return 0;
}

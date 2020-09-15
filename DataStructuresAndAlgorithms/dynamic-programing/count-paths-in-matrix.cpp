/****
The task is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.

Input: 
First line consists of T test cases. First line of every test case consists of N and M, denoting the number of rows and number of column respectively.

Output: 
Single line output i.e count of all the possible paths from top left to bottom right of a mXn matrix. Since output can be very large number use %10^9+7.

Constraints:
1<=T<=100
1<=N<=100
1<=M<=100

Example:
Input:
1
3 3
Output:
6
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	int mod=1000000007;
	cin >> t;
	while(t--)
	{
	    int m,n;
	    cin >> m >> n;
	    int dp[m][n];
	    for(int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            if(i==0 || j==0)
	                dp[i][j]=1;

	            else {
	                dp[i][j] = (dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
	            }
	        }
	    }
	    cout << dp[m-1][n-1] << endl;
	}
	return 0;
}

/****
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n and m,n is the number of rows and m is the number of columns.
The second line of each test case contains array C[n][m] in row major form.

Output:

Print maximum size square sub-matrix.

Constraints:

1 ≤ T ≤ 100
1 ≤ n,m ≤ 50
0 ≤ C[n][m] ≤ 1

Example:

Input:
3
5 6
0 1 0 1 0 1 1 0 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 1 1 1 1 1
2 2
1 1 1 1
2 2
0 0 0 0

Output:
3
2
0

Algorithm:
fill dp matrix with min(top, left, top-left)+1 and maintain max size of square
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int m, n;
	    cin >> m >> n;
	    int a[m][n];
	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++)
	            cin >> a[i][j];

	    int dp[m][n];
	    int maxi = 0;

	    for(int i=0; i<m; i++) {
	        if(a[i][0]) maxi=1;
	        dp[i][0]=a[i][0];
	    }

	    for(int j=0; j<n; j++) {
	        if(a[0][j]) maxi=1;
	        dp[0][j]=a[0][j];
	    }


	    for(int i=1; i<m; i++) {
	        for(int j=1; j<n; j++) {
	            if(a[i][j]) {
	                int mini = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
	                dp[i][j]=mini+1;
	                maxi = max(maxi, dp[i][j]);
	            }
	            else dp[i][j]=0;
	        }
	    }
	    cout << maxi << endl;
	}
	return 0;
}

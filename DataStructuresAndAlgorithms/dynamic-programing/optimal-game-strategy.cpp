/****
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)


Algorithm:
https://www.youtube.com/watch?v=WxpIHvsu1RI
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for (int i=0; i<n; i++)
	        cin >> a[i];

	    //create a 2d array of pair for both players
	    pair<int,int> dp[n][n];

	    //fill the diagonals for the case when there is only one coin
	    //then first player will win always and second will get 0 value
	    for(int i=0; i<n; i++) {
	        dp[i][i] = make_pair(a[i], 0);
	        //cout << dp[i][i].first << ", "<< dp[i][i].second << endl;
	    }

	    //fill the dp array diagonally upwards
	    //for each cell, second player will get min of the left out by first
	    for(int gap=1; gap<n; gap++) {
	        for(int i=0, j=gap; j<n; i++, j++) {
	            dp[i][j].first = max(a[i]+dp[i+1][j].second,a[j]+dp[i][j-1].second);
	            dp[i][j].second = min(dp[i+1][j].first, dp[i][j-1].first);
	            //cout << dp[i][j].first << ", "<< dp[i][j].second << endl;
	        }
	    }

	    cout << dp[0][n-1].first << endl;
	}
	return 0;
}

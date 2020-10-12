/****
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then output -1

Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V*M ≤ 106
All the elements of array are distinct
  ****/

class Solution{

	public:
	int minCoins(int coins[], int M, int V)
	{
	    // Your code goes here
		//1-D array is enough instead of 2-D
	    int dp[V+1] = {0};
		//filling with V+1 instead of INT_MAX
	    fill_n(dp+1, V, V+1);

	    sort(coins, coins+M);
	    //for(int i=0; i<V; i++) cout << dp[i]<<" "; cout << endl;

	    for(int i=0; i<M; i++) {
	        for(int j=coins[i]; j<=V; j++)
	            dp[j]=min(dp[j],dp[j-coins[i]]+1);

	        //for(int i=0; i<V; i++) cout << dp[i]<<" "; cout << endl;
	    }


	    return dp[V]>V?-1:dp[V];
	}

};

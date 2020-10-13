/****
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

Algorithm:
It is similar to coin change problem but not same
Here we cannot use one element multiple times, hence using 2D array
  ****/

// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        // code here
        int sum=0;
        for(int i=0; i<n; i++)
            sum+=a[i];

        if(sum%2==1) return 0;

        int k = sum/2;
        //sort(a, a+n);
		//using 2D array as one value cannot be repeated to calculate sum
        bool dp[n+1][k+1];

        fill_n(dp[0],k+1,false);
        for(int i=0; i<=n; i++)
            dp[i][0]=true;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=k; j++) {
				//use previous value
                if(j<a[i-1]) 
					dp[i][j] = dp[i-1][j];
                if(j>=a[i-1])
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            //for(int i=0; i<=k; i++) cout << dp[i] << " "; cout <<endl;
        }
        return dp[n][k]?1:0;
    }
};

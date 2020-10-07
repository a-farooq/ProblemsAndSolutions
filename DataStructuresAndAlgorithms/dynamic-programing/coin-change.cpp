/****
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

â€‹Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as input parameter and returns the number of ways to make change for N cents.



Expected Time Complexity: O(m*n).
Expected Auxiliary Space: O(n). 


Constraints:
1 <= n,m <= 103


  ****/

class Solution
{
    bool comb_sum(int* a, int i, int n, int sum, int k, long long& count)
    {
        while(i < n)
        {
            if(sum==k) {
                count++;
                return true;
            }
            else if(sum < k) {
                comb_sum(a, i, n, sum+a[i], k, count);
            }

            i++;
        }
    }

  public:
    long long int count( int S[], int m, int n )
    {

        //code here.
        sort(S, S+m);
        long long dp[n+1] = {0};
        dp[0]=1;
        for(int i=0; i<m; i++) {
            for(int j=S[i]; j<=n; j++) {
                dp[j] = dp[j]+dp[j-S[i]];
            }
        }
        return dp[n];
        /*
        long long int count=0;
        comb_sum(S, 0, m, 0, n, count);
        return count;*/
    }
};

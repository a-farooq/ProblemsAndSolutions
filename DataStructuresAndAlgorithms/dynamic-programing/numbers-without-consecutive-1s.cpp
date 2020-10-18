/****
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 10^9 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation: 5 strings are (000,
001, 010, 100, 101).
Example 2:

Input:
N = 2
Output: 3
Explanation: 3 strings are
(00,01,10).
Your Task:
Complete the function countStrings() which takes single integer n, as input parameters and returns an integer denoting the answer. You don't to print answer or take inputs. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^5
  ****/

//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n)
	{
	    // code here
	    int mod=1000000007;
	    ll dp0last[n];
	    ll dp1last[n];
	    dp0last[0] = dp1last[0] = 1;

	    for(int i=1; i<n; i++) {
	        dp0last[i] = (dp0last[i-1] + dp1last[i-1])%mod;
	        dp1last[i] = (dp0last[i-1])%mod;
	    }
	    return (dp0last[n-1]+dp1last[n-1])%mod;
	}
};

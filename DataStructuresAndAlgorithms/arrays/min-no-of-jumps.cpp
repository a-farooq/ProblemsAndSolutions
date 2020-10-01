/****
Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input: 
The first line contains an integer T, depicting total number of test cases.  Then following T lines contains a number n denoting the size of the array. Next line contains the sequence of integers a1, a2, ..., an.

Output:
For each testcase, in a new line, print the minimum number of jumps. If answer is not possible print "-1"(without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^7
0 <= ai <= 10^7

Example:
Input:
2
11
1 3 5 8 9 2 6 7 6 8 9
6
1 4 3 2 6 7
Output:
3
2

Explanation:
Testcase 1: First jump from 1st element, and we jump to 2nd element with value 3. Now, from here we jump to 5h element with value 9. and from here we will jump to last.
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
	    for(int i=0; i<n; i++)
	        cin >> a[i];

	    int dp[n]={0};

	    dp[0]=0;
	    int last=0;
	    for(int i=0; i<n; i++) {
	        //solution is not possible
	        if(i<n && a[i]==0 && dp[i+1]==0)
	            break;

	        int steps=a[i];
	        //update the jumps starting from last set jump
	        int j=last+1;
	        for(; j<= i+steps && j<n; j++) {
	            dp[j]=dp[i]+1;
	        }

	        //cout << i << endl;
	        //cout << last+1 << endl;
	        //for(int k=0; k<n; k++) cout << dp[k] << " "; cout << endl;

	        //end is reached
	        if(j==n)
	            break;

	        //keep the last as max set
	        last = max(last, i+steps);

	    }
	    //print -1 if no solution
	    cout << (dp[n-1]==0?-1:dp[n-1]) << endl;
	}
	return 0;
}

/****
Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4

https://www.youtube.com/watch?v=TLaGwTnd3HY
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string st;
	    cin >> st;
	    int len = st.length();
	    int dp[len][len];

	    for(int i=0; i<len; i++)
	        dp[i][i]=1;

	    for(int k=1; k< len; k++) {
	        for(int i=0; i< len-k; i++) {
	            int j=i+k;

	            if(k==1) {
	                if(st[i]==st[j]) dp[i][j]=2;
	                else dp[i][j]=1;
	            }
	            else {
    	            if(st[i]==st[j]) {
    	                dp[i][j]=dp[i+1][j-1]+2;
    	            }
    	            else {
    	                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
    	            }
	            }
	        }
	    }
	    cout << dp[0][len-1] << endl;

	}
	return 0;
}

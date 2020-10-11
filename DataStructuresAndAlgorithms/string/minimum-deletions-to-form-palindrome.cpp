/****
Given a string, find the minimum number of characters to be deleted to convert it to palindrome.
For Example:
ab: Number of deletions required is 1. bab or aba
aa: Number of deletions required is 0. aa
abcd: Number of deletions required is 3. dcbabcd

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is S.

Output:

Print the minimum number of characters.

Constraints:

1 ≤ T ≤ 50
1 ≤ S ≤ 40

Example:

Input:
3
abcd
aba
geeks

Output:
3
0
3

Algorithm:
find longest palindromic subsequence
delete its length from string length
  ****/

#include <iostream>
using namespace std;

int longest_pal_subseq(string str)
{
    int len = str.length();
    int dp[len][len];

    for(int i=0; i<len; i++)
        dp[i][i]=1;

	//k is difference between i and j to check
    for(int k=1; k<len; k++) {
        for(int i=0; i<len-k; i++) {
            int j=i+k;
            if(str[i]==str[j]) {
                if(k==1) {
                    dp[i][j]=2;
                }
                else {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    //cout << "=="<< dp[0][len-1] << endl;
    return dp[0][len-1];
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    int lpslen = longest_pal_subseq(str);
	    cout << str.length()-lpslen << endl;
	}
	return 0;
}

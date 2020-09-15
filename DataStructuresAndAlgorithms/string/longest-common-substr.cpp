/****
Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.

  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m,n;
	    cin >> m >> n;
	    int lcsuff[m+1][n+1];

	    string s1, s2;
	    cin >> s1 >> s2;

	    int result = 0;
	    for(int i=0; i<=m; i++) {
	        for(int j=0; j<=n; j++) {
	            if(i==0 || j==0) {
	                lcsuff[i][j]=0;
	            }
	            //string indices and 2d array indices are different
	            else if(s1[i-1]==s2[j-1]) {
	                lcsuff[i][j] = lcsuff[i-1][j-1]+1;
	                result = max(result, lcsuff[i][j]);
	            }
	            else lcsuff[i][j]=0;
	        }
	    }
	    cout << result << endl;
	}
	return 0;
}

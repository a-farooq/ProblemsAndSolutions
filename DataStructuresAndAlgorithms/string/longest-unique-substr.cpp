/****
Given a string, find the length of the longest substring without repeating characters. For example, the longest substrings without repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”, with length 6.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is str.

Output:

Print the length of longest substring.

Constraints:

1 ≤ T ≤ 20
1 ≤ str ≤ 50

Example:

Input:
2
seekandseek
qwertqwer

Output:
6
5

****/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string str;
	    vector<char> A(26, -1);
	    cin >> str;
	    int i = 0, j = 0;
	    int lmax = 0;

	    while(j < str.length()) {
	        char ch = str[j];
	        if(A[ch-'a'] != -1 && A[ch-'a'] >= i) {
	            i = A[ch-'a']+1;
	        }
	        A[ch-'a'] = j;
	        lmax = max(lmax, j-i+1);
	        j++;
	    }
	    cout << lmax << endl;
	}
	return 0;
}

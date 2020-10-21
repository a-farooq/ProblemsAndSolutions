/****
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 10^4

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".


  ****/

#include <iostream>
#include <cstring>
using namespace std;

// User function template for C++

// A : given string
// return the required string
string longestPalindrome(string st)
{
    // code here
    int stlen = st.length();
    int maxi=0;
    int maxi_start=0;
    for(int k=0; k<stlen; k++) {
        int i=k-1, j=k+1;
        int len=1;
        int start = k;
        //cout << k << "=>"<< i << "=>" << j << endl;
        //check for odd length palindromes
        while(i>=0 && j<stlen) {
            //cout << "====" << endl;
            if(st[i]!=st[j]) break;
            len+=2;
            start=i;
            i--;
            j++;
        }
        if(maxi<len) {
            maxi = len;
            maxi_start = start;
        }
        //cout << len<< ", "<<maxi_start << ", "<< maxi << endl;
        //check for even length palindromes
        if(k<stlen-1 && st[k]==st[k+1]) {
            i=k-1;
            j=k+2;
            len=2;
            start=k;
            while(i>=0 && j<stlen) {
                if(st[i]!=st[j]) break;
                len+=2;
                start=i;
                i--;
                j++;
            }
            if(maxi<len) {
                maxi = len;
                maxi_start = start;
            }
            //cout << len<<", "<<maxi_start << ", "<< maxi << endl;
        }

    }
    //cout << maxi_start << ", "<< maxi << endl;
    return st.substr(maxi_start, maxi);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string st;
	    cin >> st;
	    cout << longestPalindrome(st) << endl;
	}
	return 0;
}

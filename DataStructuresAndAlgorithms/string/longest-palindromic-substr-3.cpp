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
string longest_palindrome(string st)
{
    int start=0;
    int maxlen=0;

    for(int i=0; i<st.length(); i++) {
        for(int len=st.length()-i; len>0 && len>maxlen; len--) {
            //cout << "i: "<<i<<", j: "<<j<<endl;
            string subst = st.substr(i,len);
            
            string substr = subst;
            reverse(substr.begin(), substr.end());
            
            //cout << subst << "--"<<substr<<endl;

            if(subst==substr) {
                maxlen=len;
                //cout << "i: "<<i<<", j: "<<j<<endl;
                //cout << "maxlen: "<<maxlen<<endl;
                start=i;
                break;
            }
        }
    }
    return st.substr(start, maxlen);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string st;
	    cin >> st;
	    cout << longest_palindrome(st) << endl;
	}
	return 0;
}

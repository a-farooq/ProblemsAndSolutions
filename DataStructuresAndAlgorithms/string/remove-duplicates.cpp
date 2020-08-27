/****
Given a string which may contains lowercase and uppercase chracters. The task is to remove all  duplicate characters from the string and print the resultant string.  The order of remaining characters in the output should be same as in the original string.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains a string.

Output:
Print the resultant string after removing duplicate characters from string.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
geeksforgeeks
HappyNewYear

Output:
geksfor
HapyNewYr

Explanation:
Testcase 1: After removing duplicate characters such as e, k, g, s, we have string as geksfor.
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;

	cin >> t;
	while(t--)
	{
	    //short lower[26] = {0};
	    //short upper[26] = {0};
	    //short digit[10] = {0};
	    short chars[130] = {0};
	    string str;
	    cin >> str;
	    for(char ch : str) {
	        if(!chars[ch]) {
	            chars[ch] = 1;
	            cout << ch;
	        }
	        /*
	        bool flag = true;
	        if(ch >= 'a' && ch <= 'z') {
	            if(lower[ch-'a']) flag = false;
	            else lower[ch-'a'] = 1;
	        }
            else if(ch >= 'A' && ch <= 'Z') {
                if(upper[ch-'A']) flag = false;
                else upper[ch-'A'] = 1;
            }
            else if(ch >= '0' && ch <= '9') {
                if(digit[ch-'0']) flag = false;
                else digit[ch-'0'] = 1;
            }
            if(flag) cout << ch;*/
	    }
	    cout << endl;
	}
	return 0;
}

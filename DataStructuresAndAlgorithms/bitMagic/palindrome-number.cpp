/****
Check if binary representation of a number is palindrome
Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.
Output:
Each seperate line showing output 0(False) or 1 (True).
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^18
Example:
Input:
2
999
17
Output:
0
1
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    unsigned long n;
	    cin >> n;
	    if(!n&1) { //if n is even, it cant be palindrome
	        cout << 0 << endl;
	    }
	    else {
	        string st = "";
	        while(n) { //convert n into string of binary
	            if(n & 1) st += '1';
	            else st += '0';
	            n = n >> 1;
	        }
	        int i=0, j=st.length()-1;
	        bool flag = true;
	        while(i < j)
	            if(st[i++]!=st[j--]) { flag = false; break; }

	        cout << (flag?1:0) << endl;
	    }
	}
	return 0;
}

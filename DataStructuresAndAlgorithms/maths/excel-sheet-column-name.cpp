/****
Given a positive integer N, print its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.

Output:
For each testcase, in a new line, print the string corrosponding to the column number.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107

Example:
Input:
7
26
51;
52
80
676
702
705
Output:
Z
AY
AZ
CB
YZ
ZZ
AAC
  ****/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    string st="";
	    while(n) {
	        int m=n%26;
	        if(m==0) {
	            st += 'Z';

				n--;
	            //n=n/26-1;
	        }
            else {
    	        st += 'A'+m-1;
	            //n=n/26;
            }
			n/=26;
	    }
	    reverse(st.begin(), st.end());
	    cout << st << endl;
	}
	return 0;
}

/****
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:

Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.


Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input:
2
000000
1234123

Output:
6
4
  ****/
#include <iostream>
using namespace std;

int main() {
	int t, maxlen;
	cin >> t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    int len = str.length();
	    int sum[len];
	    maxlen = 0;

	    for(int i =0 ; i < len-1; i++)
	    {
	        sum[i] = str[i]-'0';
	        //if(len-i <= maxlen) break;

	        for(int j = i+1; j < len; j++)
	        {
	            int digit = str[j]-'0';
	            sum[j] = sum[j-1]+digit;
	            //cout << "--" << i << ", "<< j << ", "<< j-i+1 << endl;
	            int sublen = j-i+1;
	            if(sublen%2 == 0) { //j is even
	                int k = i-1+sublen/2; //half of substr
	                //cout << "==="<<k<< ","<< sum[k] << ","<<j<<","<<sum[j]<<endl;
	                if(sum[j] == sum[k]*2)
	                {
	                    maxlen = max(maxlen, sublen);
	                }
	                //cout << "maxlen: "<< maxlen << endl;
	            }
	            //for(int k=i; k <= j; k++) cout << sum[k] << " ";
	            //cout << endl;
	        }
	    }
	    cout << maxlen << endl;
	}
	return 0;
}

/****
Given two binary strings s1 and s2. Print the resultant string after adding given two binary strings.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case contains two binary strings s1 and s2 separated by space.

Output:
For each test case print the resultant binary string.

Constraints:
1 <= T <= 70
1 <= |s1|, |s2| <= 200, where |s| represents the length of string s

Example:
Input:
2
1101 111
10 01

Output:
10100
11
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s1, s2, s="";
	    cin >> s1 >> s2;
	    int i = s1.length()-1, j = s2.length()-1;
	    int c = 0;
	    while(i >= 0 || j >= 0)
	    {
	        int a=0, b=0;
	        if(i>=0 && s1[i]=='1') a = 1;
	        if(j>=0 && s2[j]=='1') b = 1;

	        int d = a+b+c;
	        //cout << "d: "<< d << endl;
	        /*
	        switch(d) {
	            case 0: s = '0'+s; c=0; break;
	            case 1: s = '1'+s; c=0; break;
	            case 2: s = '0'+s; c=1; break;
	            case 3: s = '1'+s; c=1; break;
	        }*/

	        c=d/2;
	        //int k=d%2;
	        s=to_string(d%2)+s;

	        i--;
	        j--;
	    }
	    if(c) s = '1'+s;

	    cout << s << endl;
	}
	return 0;
}

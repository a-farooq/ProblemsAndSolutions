/****
Design a system that takes big URLs like “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/” and converts them into a short 6 character URL. It is given that URLs are stored in database and every URL has an associated integer id.  So your program should take an integer id and generate a 6 character long URL. 

A URL character can be one of the following

A lower case alphabet [‘a’ to ‘z’], total 26 characters
An upper case alphabet [‘A’ to ‘Z’], total 26 characters
A digit [‘0′ to ‘9’], total 10 characters
There are total 26 + 26 + 10 = 62 possible characters.

So the task is to convert an integer (database id) to a base 62 number where digits of 62 base are "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

Input:
The first line of input contains an integer T denoting the number of test cases. The second line consists of a long integer.

Output:
For each testcase, in a new line, print the shortened string in the first line and convert the shortened string back to ID (to make sure that your conversion works fine) and print that in the second line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 232-1

Example:
Input:
1
12345

Output:
dnh
12345
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	string in = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	while(t--)
	{
	    long n;
	    cin >> n;
	    string out = "";
	    while(n) {
	        int r = n%62;
	        n /= 62;
	        //cout << r << " ";
	        out = in[r] + out;
	    }
	    cout << out << endl;
	    int i=0;//out.size()-1;
	    int k=0;
	    while(i<out.size()) {
	        int j=0;
	        if(out[i]>='a' && out[i]<='z')
	            j=out[i]-'a';
	        else if(out[i]>='A' && out[i]<='Z')
	            j=out[i]-'A'+26;
	        else if(out[i]>='0' && out[i]<='9')
	            j=out[i]-'0'+52;

	        k=k*62+j;
	        i++;
	        //cout << j << ", "<<k << " ";
	    }
	    cout << k << endl;

	}
	return 0;
}

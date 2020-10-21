/****
For a given string delete the elements which are appearing more than once consecutively. All letters are of lowercase.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases,  a string will be inserted.


Output:
In each seperate line the modified string should be output.


Constraints:
1<=T<=31
1<=length(string)<=100


Example:
Input:
1
aababbccd

Output:
ababcd
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string st;
	    cin >> st;

	    for(int j=0; j<st.length(); j++)
	        if(j==0 || st[j]!=st[j-1])
	            cout <<st[j];
	    cout << endl;
	}
	return 0;
}

/****
blems
Given an array containing integers, zero is considered an invalid number and rest all other numbers are valid. If two nearest valid numbers are equal then double the value of the first one and make the second number as 0.At last move all the valid numbers on the left.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The next line consists of n spaced integers.

Output:
Print the resultant array.

Constraints: 
1<=T<=100
1<=N<=10000
1<=A[i]<=10000

Example:
Input:
1
12
2 4 5 0 0 5 4 8 6 0 6 8

Output:
2 4 10 4 8 12 8 0 0 0 0 0
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];

	    int i = 0, j = 0;

        while(j < n) {
			//move i to first 0
	        while(a[i] != 0) {
	            if(i > 0 && a[i] == a[i-1]) {
	                a[i-1] *= 2;
	                a[i] = 0;
	            }
	            else i++;
	        }

			//move j to first non zero after i
	        if(j == 0) j = i+1;
	        while(a[j] == 0 && j < n) j++;

	        if(j >= n) break;

	        swap(a[i], a[j]);

	        if(i > 0 && a[i] == a[i-1]) {
	            a[i-1] *= 2;
	            a[i] = 0;
	        }
	    }

	    for(auto val : a) cout << val << " ";
	    cout << endl;
	}
	return 0;
}

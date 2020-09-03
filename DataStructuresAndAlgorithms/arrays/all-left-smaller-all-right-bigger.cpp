/****
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 10^6
1 <= A[i] <= 10^6

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.


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
	    for(int i=0; i<n; i++) cin >> a[i];

	    int left[n];
	    int right[n];

	    left[0] = a[0];
	    for(int i=1; i<n; i++)
	        left[i] = max(a[i-1], left[i-1]);

	    right[n-1]=a[n-1];
	    for(int i=n-2; i>=0; i--)
	        right[i]=min(a[i+1], right[i+1]);

	    //for(int i=0; i<n; i++) cout << left[i] << " "; cout << endl;
	    //for(int i=0; i<n; i++) cout << right[i] << " "; cout << endl;

		//if max of all lefts is smaller, all on left will be smaller
		//if min of all rights is bigger, all on right will be bigger
	    int i;
	    for(i = 1; i<n-1; i++)
	        if(left[i] <= a[i] && a[i] <= right[i]) break;

	    cout << (i<n-1?a[i]:-1) << endl;
	}
	return 0;
}

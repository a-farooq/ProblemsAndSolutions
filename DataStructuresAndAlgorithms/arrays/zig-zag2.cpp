/****
Given a sorted array arr[] of non-repeating integers without duplicates. Sort the array into a wave-like array and return it. In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order).

Input:
The first line contains an integer T, depicting total number of test cases. T testcases follow. The first line of each testcase contains an integer N depicting the size of the array. The second line contains N space separated elements of the array.

Output:
For each testcase, in a new line, print the array into wave-like array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^6
0 ≤ A[i] ≤10^7

Example:
Input:
1
5
1 2 3 4 5
Output:
2 1 4 3 5

Explanation:
Testcase 1: Array elements after sorting it in wave form are 2 1 4 3 5.


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
	    /*
	    for(int i=0; i<n; i++) {
	        if(i%2==0 && i<n-1 && a[i]<a[i+1]) swap(a[i], a[i+1]);

	        if(i%2==1 && i<n-1 && a[i]>a[i+1]) swap(a[i], a[i+1]);

	        //for(int i=0; i<n; i++) cout << a[i] << " "; cout << endl;
	    }
	    */
	    for(int i=0; i<n-1; i+=2) {
	        swap(a[i], a[i+1]);
	    }

	    for(int i=0; i<n; i++) cout << a[i] << " "; cout << endl;
	}
	return 0;
}

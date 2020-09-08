/****
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then T test case follows. First line of each test case contains an integer N denoting the size of the array. Next line contains N space separated integeres denoting the elements of the array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 10^3
0 ≤ A[i] ≤ 10^18

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
Testcase 1:  In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).


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
	    long a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];

	    int maxi = 0;
	    for(int i=0; i<n; i++) {
	        int j = n-1;
	        //cout << a[i] << ", "<< a[j] << endl;
	        while(j>i && j-i>maxi && a[j]<a[i]) {
	            //cout << a[i] << ", "<< a[j] << endl;
	            j--;
	        }
	        //cout << a[i] << ", "<< a[j] << endl;
	        //cout << "j-i: "<< j-i << endl;
	        maxi=max(maxi, j-i);
	    }
	    cout << maxi << endl;
	}
	return 0;
}

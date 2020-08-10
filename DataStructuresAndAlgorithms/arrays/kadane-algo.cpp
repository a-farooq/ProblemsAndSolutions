/******
Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 10^6
-10^7 ≤ A[i] <= 10^7

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
*****/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//int a[1000005];

int main() {
	//code
	int t, n, k;
	int msf, meh;
	cin >> t;
	while(t--)
	{
	    msf = INT_MIN; 
	    meh = 0;
	    cin >> n;
	    for(auto i = 0; i < n; i++) {
	        cin >> k;
	        meh = meh + k;
	        
	        if(meh < k) meh = k;
	        if(msf < meh) msf = meh;
	    }
	    cout << msf << endl;
	}
	return 0;
}

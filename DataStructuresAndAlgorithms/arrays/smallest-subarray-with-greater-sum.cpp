/****
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers N and x. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required ouput.

Constraints:
1<=T<=100
1<=N,x<=1000
1<=A[]<=1000

Example:
Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7
Output:
3
1

Solution:
if sum is lesser, expand window size to right
else shrink window size from left
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, x;
	    cin >> n >> x;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];

	    int i=0, j=0;
	    int sum=a[0];
	    int mini = n;
	    while(j<n) {
	        //cout <<"i: "<<i<<", j: "<<j<<", sum: "<<sum<<endl;
	        if(sum>x) {
	            int len = j-i+1;
	            mini = min(mini, len);
	            sum -= a[i++];
	            //cout << "mini: "<<mini<<endl;
	        }
	        else {
	            sum+=a[++j];
	        }
	    }
	    cout << mini << endl;
	}
	return 0;
}

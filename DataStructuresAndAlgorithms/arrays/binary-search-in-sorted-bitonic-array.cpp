/****
An array is called Bitonic if it is comprises of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Given a bitonic array A of N distinct integers. Find a element X in it.

Input:
First line will consist  a number T, the number of test cases. First line of each test case will consist of positive integer N. Next line contains array elements and third line contains X.

Output:
Print the index where element found. If element not found, print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 10^7
-10^7 <= Ai <= 10^7

Example:
Input:
1
5
1 2 7 4 3
2
Output:
1

Explanation:
Testcase 1: 2 is found at index 1 in the given array.


  ****/

#include <iostream>
using namespace std;

int bin_search(int* a, int l, int r, int x, bool decr=false)
{
    while(l<=r)
    {
        int mid = l+ (r-l)/2;
        //cout << l << ", " << r << ", " << mid << endl;

        if(a[mid]==x) return mid;

        else if(a[mid]<x) {
            if(decr) r = mid-1;
            else l = mid+1;
        }

        else {
            if(decr) l = mid+1;
            else r = mid-1;
        }
    }
    return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    bool flag = false;
	    int j=n;
	    cin >> a[0];
	    for(int i = 1; i < n; i++) {
	        cin >> a[i];

	        if(!flag && a[i] < a[i-1]) {
	            flag = true;
	            j = i;
	        }
	    }
	    int x;
	    cin >> x;

	    int idx = bin_search(a, 0, j-1, x);
	    if(idx==-1) idx = bin_search(a, j, n-1, x, true);

	    cout << idx << endl;
	}
	return 0;
}

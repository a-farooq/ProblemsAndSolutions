/****
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.

Output:
Corresponding to each test case, output the index of the element found in the array.  If element is not present, then output -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^7
0 ≤ Ai ≤ 10^8
1 ≤ K ≤ 10^8

Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1

Explanation:
Testcase 1: 10 is found at index 5.


  ****/

#include <iostream>
using namespace std;

int bin_search(int* a, int l, int r, int x)
{
    while(l<=r)
    {

        int mid = l+ (r-l)/2;
        //cout << l << ", " << r << ", " << mid << endl;

        if(a[mid]==x) return mid;

        else if(a[mid]<x) l = mid+1; //return bin_search(a, mid+1, r, x); //l = mid+1;

        else r = mid-1; //bin_search(a, l, mid-1, x); //r = mid-1;
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
	    int pre;
	    bool flag = false;
	    int j=n;
	    cin >> a[0];
	    pre = a[0];
	    for(int i = 1; i < n; i++) {
	        cin >> a[i];

	        if(!flag && a[i] < pre) {
	            flag = true;
	            j = i;
	        }
	        pre = a[i];
	    }
	    int x;
	    cin >> x;

	    int idx = bin_search(a, 0, j-1, x);
	    if(idx==-1) idx = bin_search(a, j, n-1, x);

	    cout << idx << endl;
	}
	return 0;
}

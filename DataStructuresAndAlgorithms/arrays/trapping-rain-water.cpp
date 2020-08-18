/****
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1. Compute how much water can be trapped in between blocks after raining.
Structure is like below:
|  |
|_|
We can trap 2 units of water in the middle gap.
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 10ˆ7
0 <= Ai <= 10ˆ8

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Testcase 1: Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.

  ****/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, sum = 0;
	    cin >> n;
	    vector<int> a(n,0), lmax(n, 0), rmax(n, 0);
	    for(int i = 0; i < n; i++)
	        cin >> a[i];

		//find max height at left of each index
	    for(int i = 1; i < n; i++)
	        lmax[i] = max(lmax[i-1], a[i-1]);

		//find max height at right of each index
	    for(int i = n-2; i >= 0; i--)
	        rmax[i] = max(rmax[i+1], a[i+1]);

		//water trapped will be the diff of min of left & right height & current value at each index
	    for(int i = 0; i < n; i++) {
	        int k = min(lmax[i], rmax[i]) - a[i];
	        if(k > 0) sum += k;
	    }
	    cout << sum << endl;
	}
	return 0;
}

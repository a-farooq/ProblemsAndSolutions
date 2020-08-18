/****
Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.
Testcase 2: 4th smallest elemets in the given array is 15.
  ****/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k, t;
	    cin >> n;
	    int a[n];
	    //vector<int> a(n);
	    //set<int> nset;
	    for(int i = 0; i < n; i++) {
	        cin >> t;
	        a[i] = t;
	        //nset.insert(t);
	    }

	    cin >> k;
	    sort(a, a+n);
	    //sort(begin(a), end(a), [](const int &x, const int& y){ return x < y; });

	    //for(int k : a)
	    //    cout << k << " ";
	    /*
	    int i = 1;
	    for_each(begin(nset), end(nset), [i, k](int t) mutable
	    { if(i++ == k) { cout << t; return; } });
	    cout << endl;*/
	    cout << a[k-1] << endl;
	}
	return 0;
}

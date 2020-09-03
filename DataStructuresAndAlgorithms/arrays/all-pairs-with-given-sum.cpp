/****
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 3 lines . The first line contains 3 space separated integers N, M, X. Then in the next two lines are space separated values of the array A and B respectively.

Output:
For each test case in a new line print the sorted space separated values of all the pairs u,v where u belongs to array A and v belongs to array B, such that each pair is separated from the other by a ',' without quotes also add a space after the ',' . If no such pair exist print -1.

Constraints:
1 <= T <= 100
1 <= N, M, X <= 10^6
-10^6 <= A, B <= 10^6

Example:
Input:
2
5 5 9
1 2 4 5 7
5 6 3 4 8
2 2 3
0 2
1 3
Output:
1 8, 4 5, 5 4
0 3, 2 1

Explanation:
Testcase 1: (1, 8), (4, 5), (5, 4) are the pairs which sum to 9.


  ****/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    unordered_map<int,int> um;
	    int m, n, num;
	    cin >> m >> n >> num;
	    int a[m];

	    for(int i=0; i<m; i++)
	        cin >> a[i];


	    for(int i=0; i<n; i++) {
	        int t;
	        cin >> t;
	        um[t]++;
	    }

	    //sort the first array as the output must be ordered on first array
	    sort(a, a+m);
	    bool found = false;
	    if(um[num-a[0]]>0) {
            cout << a[0] << " " << num-a[0];
            found = true;
	    }

	    for(int i=1; i<m; i++) {
	        if(um[num-a[i]]>0) {
	            if(found) cout << ", ";
	            cout << a[i] << " " << num-a[i];
	            found = true;
	        }
	    }

	    if(!found) cout << -1;
	    cout << endl;
	}
	return 0;
}

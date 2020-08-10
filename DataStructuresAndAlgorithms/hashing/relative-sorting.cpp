/*******
Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
Note: Expected time complexity is O(N log(N)).

Input:
First line of input contains number of testcases. For each testcase, first line of input contains length of arrays N and M and next two line contains N and M elements respectively.

Output:
Print the relatively sorted array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N,M  ≤ 10^6
1 ≤ A1[], A2[] <= 10^6

Example:
Input:
2
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
8 4
2 6 7 5 2 6 8 4 
2 6 4 5
Output:
2 2 1 1 8 8 3 5 6 7 9
2 2 6 6 4 5 7 8

Explanation:
Testcase 1: After sorting the resulted output is 2 2 1 1 8 8 3 5 6 7 9.
Testcase 2: After sorting the resulted output is 2 2 6 6 4 5 7 8.
*****/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1000005
int a[MAX];
int a1[MAX];
//int a2[MAX];

int main() {
	//code
	int t;
	int n, m, k;

	
	cin >> t;
	while(t--) 
	{
	    memset(a, 0, MAX);
	    cin >> n >> m;
	    int max = 0;
	    for(auto i = 0; i < n; i++)
	    {
	        cin >> a1[i];
	        max = max < a1[i] ? a1[i] : max;
	        a[a1[i]]++;
	    }
	    
	    for(auto i = 0; i < m; i++)
	    {
	        cin >> k;
	        while(a[k]) {
	            cout << k << " ";
	            a[k]--;
	        }
	    }
	    
	    for(auto i = 0; i <= max; i++) {
	        while(a[i]) {
	            cout << i << " ";
	            a[i]--;
	        }
	    }
	    
	    cout << endl;
	}
	return 0;
}

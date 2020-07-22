/*******
Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader. 

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 10^7
0 <= Ai <= 10^7

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. Also, all the elements of right side of 7 (at index 3) are smaller than 7. And, the last element 3 is itself a leader since no elements are on its right.
*******/


#include <iostream>
using namespace std;
int a[10000005];

int main() {
	//code
	int t, n;
	cin >> t;
	while(t--)
	{
	    int mth = -1; //max till here
	    cin >> n;
	    int ind = n; //last leader index
	    for(auto i = 0; i < n; i++)
	        cin >> a[i];
	        
	    for(auto i = n-1; i >= 0; i--) {
	        if(a[i] >= mth) {
	            mth = a[i];
	            a[--ind] = a[i];
	        }
	    }
	    
	    for(auto i = ind; i < n; i++)
	        cout << a[i] << " ";
	    cout << endl;
	}
	return 0;
}

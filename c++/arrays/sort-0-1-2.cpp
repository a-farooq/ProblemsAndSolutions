/******
Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
******/


#include <iostream>
using namespace std;
int a[1000005];

int main() {
	//code
	int t, n;
	int l, r, i;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    for(auto i = 0; i < n; i++)
	        cin >> a[i];
	    
	    l = 0;
	    r = n-1;
	    int i;
	    
	    while(a[l]==0) l++;
	    while(a[r]==2) r--;
	    
	    //cout << l << ", " << r << endl;
	    i = l; 
	    while(i <= r)
	    {
	        if(a[i]==0) swap(a[l++], a[i++]);
	        else if(a[i]==2) swap(a[r--], a[i]);
	        else i++;
	    }
	    //cout << l << ", " << r << ", " << i << endl;
	    
	    for(i = 0; i < n; i++)
	        cout << a[i] << " ";
	    cout << endl;
	}
	return 0;
}

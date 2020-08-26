/****
Given an array A of N positive integers and another number X. Determine whether or not there exist two elements in A whose sum is exactly X.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N and X, N is the size of array. The second line of each test case contains N integers representing array elements A[i].

Output:
Print "Yes" if there exist two elements in A whose sum is exactly X, else "No" (without quotes).

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5

Example:
Input:
2
6 16
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
Yes
Yes

Explanation:
Testcases 1: 10 and 6 are numbers making a pair whose sum is equal to 16.
  ****/

#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int *a, int n, int x)
{
    int l = 0, r = n; //mid = l+(r-l+1)/2;
    while(l <= r)
    {
        int mid = l+(r-l+1)/2;
        if(x == a[mid]) return true;

        if(x < a[mid]) r = mid-1;

        else l = mid+1;
    }
    return false;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, x;
	    cin >> n >> x;
	    int a[n];
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    sort(a, a+n); //nlogn
	    //for(auto val : a) cout << val << " ";
	    bool ret = false;
	    for(int i = n-1; i > 0; i--) { //nlogn
	        ret = binary_search(a, i-1, x-a[i]);
	        if(ret) break;
	    }

	    cout << (ret? "Yes" : "No") << endl;
	}
	return 0;
}

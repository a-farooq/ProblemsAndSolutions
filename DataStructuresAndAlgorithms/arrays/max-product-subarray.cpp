/****
Given an array A that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray such that after taking the mod by 1000000007, the product is maximum.

Input:
First line of input contain number of test cases T. First line of test case contain the size of array and second line of test case contain the array elements.

Output:
Output the maximum product of subarray.

Constraints:
1 <= T <= 100
1 <= N <= 10^4
-10^4 <= Ai <= 10^4

Example:
Input:
3
5
6 -3 -10 0 2
6
2 3 4 5 -1 0 
10
8 -2 -2 0 8 0 -6 -8 -6 -1

Output:
180
120
288

Explanation:
Testcase 1: Subarray with maximum product is 6, -3, -10 which gives product as 180.

https://www.youtube.com/watch?v=vtJvbRlHqTA
****/

#include <iostream>
using namespace std;

#define mod 1000000007

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    long n, num;
	    cin >> n;
	    cin >> num;
	    long maxi = num;
	    long mini = num;
	    long maxp = num;
	    long prev_max = num;
	    long prev_min = num;

	    for(long i = 1; i < n; i++) {
	        cin >> num;
	        //if(num<0) swap(maxi, mini);

	        maxi = max(max(num, (prev_max*num)%mod), (prev_min*num)%mod);
	        mini = min(min(num, (prev_max*num)%mod), (prev_min*num)%mod);
	        maxp = max(maxp, maxi);
	        prev_max = maxi;
	        prev_min = mini;

	        //cout <<"num: "<<num<<", maxi: "<<maxi<<", mini: "<<mini<<", maxp: "<<maxp<<endl;
	    }
	    cout << maxp << endl;
	}
	return 0;
}

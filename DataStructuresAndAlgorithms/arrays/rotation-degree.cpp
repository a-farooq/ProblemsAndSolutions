/****
Given a sorted array A of size N. The array is rotated 'K' times. Find the value of 'K'. The array may contain duplicate elements.

Input:
The first line contains an integer T, depicting total number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains an integer N depicting the size of array. The next line contains elements of the array separated by spaces.

Output:
For each testcase, print the value of K.

Constraints:
1 <= T <= 100
1 <= N <=10^7
0 <= Ai <= 10^18

Example:
Input
2
5
5 1 2 3 4
5
1 2 3 4 5
Output
1
0

Explanation:
Testcase1: 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    long a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];


	    int i;
	    for(i=0; i<n-1; i++)
	        if(a[i+1] < a[i]) break;

	    cout << (i+1)%n << endl;
	    /*
	    for(i=n-1; i> 0; i--)
	        if(a[i]<a[i-1]) break;

	    cout << (i)%n << endl;*/
	}
	return 0;
}

/*********
  Given 2 sorted arrays A and B of size N each. Print sum of middle elements of the array obtained after merging the given arrays.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single positive integer N denoting the size of array. The second line contains the N space separated positive integers denoting the elements of array A. The third line contains N space separated positive integers denoting the elements of array B.

Output:
For each testcase, print the sum of middle elements of two sorted arrays. The number of the elements in the merged array are even so there will be 2 numbers in the center n/2 and n/2 +1. You have to print their sum.

Constraints:
1 <= T <= 50
1 <= N <= 10ˆ3
1 <= A[i] <= 10ˆ6
1 <= B[i] <= 10ˆ6

Example:
Input :
1
5
1 2 4 6 10
4 5 6 9 12

Output :
11

Explanation:
Testcase 1: After merging two arrays, sum of middle elements is 11 (5 + 6).
  *******/


#include <iostream>
#include <vector>
using namespace std;
int a1[1000005];
int a2[1000005];

int main() {
	//code
	int t, n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    for(auto i = 0; i < n; i++)
	        cin >> a1[i];
	    for(auto i = 0; i < n; i++)
	        cin >> a2[i];

	    auto i = 0, j = 0, k = 0;
	    //vector<int> vec;
		int m1=0, m2=0;
	    while(i < n && j < n) {
	        if(a1[i]<=a2[j]) {
	            //vec.push_back(a1[i]);
				m1=m2;
				m2=a1[i];
	            i++;
	        }
	        else {
	            //vec.push_back(a2[j]);
				m1=m2;
				m2=a2[j];
	            j++;
	        }
			if(k==n) break;
	        k++;
	    }
	    //if(i < n) vec.push_back(a1[i]);
	    //if(j < n) vec.push_back(a2[j]);
	    //cout << vec[n-1]+vec[n] << endl;
		cout << m1+m2 << endl;
	}
	return 0;
}

/********
You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is N.

Output:
For each testcase, in a new line, print the total count of all bits.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103

Example:
Input:
2
4
17
Output:
5
35

Explanation:
Testcase1:
An easy way to look at it is to consider the number, n = 4:
0 0 0 = 0
0 0 1 = 1
0 1 0 = 1
0 1 1 = 2
1 0 0 = 1
Therefore , the total number of bits is 5.
*******/

#include <iostream>
using namespace std;
#define MAX 1005

int main() {
	//code
	int t, n;
	int a[MAX] = {0};
	int sum = 0;
	int cur = 0;
	for(auto i = 1; i < MAX; i++)
	{
	    cur = 0;
	    int j = i;
	    
	    while(j) { //the loop will run by the times equal to set bit in j
	        j = j&(j-1);
	        ++cur;
	    }
	    /*
	    while(j) {  //second approach
	        if(j&1) ++cur;
	        j >>= 1;
	    }
	    */
	    sum += cur;
	    a[i] = sum;
	}
	
	//for(auto i = 0; i < MAX; i++)
	//    cout << a[i] << " ";
	//cout << endl;
	
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    cout << a[n] << endl;
	}
	return 0;
}

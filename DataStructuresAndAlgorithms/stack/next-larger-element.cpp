/****
Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 10^7
1 <= Ai <= 10^18
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.

Algorithm:

  ****/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    long long a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];

		//stack to push indices
	    stack<long long> stk;

	    for(int i=0; i<n; i++) {
	        while(!stk.empty() && a[i] > a[stk.top()]) {
				//replace array element with the next larger element
				//element at i is next larger for all the popped elements
	            a[stk.top()]=a[i];
	            stk.pop();
	        }
	        stk.push(i);
	    }

		//elements remaining on stack dont have any next larger element
	    while(!stk.empty()) {
	        a[stk.top()]=-1;
	        stk.pop();
	    }

	    for(auto i=0; i<n; i++) cout << a[i] << " ";
	    cout << endl;
	}
	return 0;
}

/****

 Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. T test-cases follow. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the array represents the height of the bars.

Output:
For each test-case, in a separate line, the maximum rectangular area possible from the contiguous bars.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[i] <= 104

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9

Explanation:
Testcase1:
 ****/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int hist[n];
	    for(int i=0; i<n; i++)
	        cin >> hist[i];

	    int i=0;
	    stack<int> stk;
	    int max_area=0;
	    while(i<n)
	    {
			//stack must have indices of bars in non-decreasing heights
			//increment i here only
	        if(stk.empty() || hist[i]>=hist[stk.top()])
	            stk.push(i++);

	        else {
	            int tp = stk.top();
	            stk.pop();

				//calculating area with top's height and diff with prev bar index (as width)
	            int area_with_top = hist[tp] * (stk.empty()?i:i-stk.top()-1);

	            max_area = max(max_area, area_with_top);
	        }
	    }
	    while(!stk.empty()) {
	        int tp = stk.top();
            stk.pop();

            int area_with_top = hist[tp] * (stk.empty()?i:i-stk.top()-1);
            max_area = max(max_area, area_with_top);
	    }
	    cout << max_area << endl;
	}
	return 0;
}

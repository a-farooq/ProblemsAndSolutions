/****
Given an input stream of n integers, find the kth largest element for each element in the stream.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two lines. The first line of each test case contains two space separated integers k and n . Then in the next line are n space separated values of the array.

Output:
For each test case, in a new line, print the space separated values denoting the kth largest element at each insertion, if the kth largest element at a particular insertion in the stream doesn't exist print -1.

Constraints:
1 <= T <= 100
1 <= K <= n
1 <= n <= 10^6
1 <= stream[] <= 10^5

Example:
Input:
2
4 6
1 2 3 4 5 6
1 2
3 4

Output:
-1 -1 -1 1 2 3
3 4 

Explanation:
Testcase1:
k = 4
For 1, the 4th largest element doesn't exist so we print -1.
For 2, the 4th largest element doesn't exist so we print -1.
For 3, the 4th largest element doesn't exist so we print -1.
For 4, the 4th largest element is 1 {1, 2, 3, 4}
For 5, the 4th largest element is 2 {2, 3, 4 ,5}
for 6, the 4th largest element is 3 {3, 4, 5}

Solution:
Maintain a Minheap of size K, thus heap will contain minimum element at the top in that pile size. 
Remove top element if new element is greater than top and insert new element from input array.
  ****/

#include <iostream>
#include <queue>
using namespace std;

class cmp
{
public:
	bool operator()(int &A,int &B)
	{
		return A > B;
	}
};

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int k, n;
	    cin >> k >> n;
	    //priority_queue<int, vector<int>, greater<int>> minheap;
	    priority_queue<int, vector<int>, cmp> minheap;

	    int t;
	    for(int i=0; i<n; i++) {
	        cin >> t;
	        if(minheap.size()<k) {
	            minheap.push(t);
	        }
	        else {
	            if(minheap.top()<t) {
	                minheap.pop();
	                minheap.push(t);
	            }
	        }

	        if(minheap.size()<k)
	            cout << -1 << " ";
	        else cout << minheap.top() << " ";
	    }
	    cout << endl;
	}
	return 0;
}

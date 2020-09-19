/****
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 10^6
1 <= x <= 10^6
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

Solution:
We can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective median from the root of heap containing more elements.

https://www.youtube.com/watch?v=1CxyVdA_654
  ****/


#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
	priority_queue<int> pqmax;
	priority_queue<int, vector<int>, greater<int>> pqmin;
	int n, x, median;
	cin >> n;
	if(n--) {
    	cin >> x;
    	pqmax.push(x);
    	cout << x << endl;
	}
	if(n--) {
    	cin >> x;
    	if(x > pqmax.top()) {
    	    pqmin.push(x);
    	}
    	else {
    	    pqmin.push(pqmax.top());
    	    pqmax.pop();
    	    pqmax.push(x);
    	}
    	median = (pqmax.top()+pqmin.top())/2;
    	cout << median << endl;
	}
	while(n--)
	{
	    cin >> x;
	    //maxtop = pqmax.top();
	    //mintop = pqmin.top();


	    if(x <= pqmax.top()) {
	        pqmax.push(x);
	    }
	    else {
	        pqmin.push(x);
	    }
	    int maxsize = pqmax.size();
	    int minsize = pqmin.size();

	    int diff = abs(maxsize - minsize);
	    if(diff == 0) {
	        median = (pqmax.top()+pqmin.top())/2;
	    }
	    else if(diff == 1) {
	        if(maxsize > minsize)
	            median = pqmax.top();
	        else median = pqmin.top();
	    }
	    else {
	        if(maxsize > minsize) {
	            int t = pqmax.top();
	            pqmax.pop();
	            pqmin.push(t);
	        }
	        else {
	            int t = pqmin.top();
	            pqmin.pop();
	            pqmax.push(t);
	        }
	        median = (pqmax.top()+pqmin.top())/2;
	    }
	    cout << median << endl;
	}
	return 0;
}

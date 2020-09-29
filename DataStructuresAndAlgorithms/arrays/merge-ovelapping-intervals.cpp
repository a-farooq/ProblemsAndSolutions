/****
Given a collection of Intervals,merge all the overlapping Intervals.
For example:

Given [1,3], [2,6], [8,10], [15,18],

return [1,6], [8,10], [15,18].

Make sure the returned intervals are sorted.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the number of Intervals and next line followed by the intervals starting and ending positions 'x' and 'y' respectively.


Output:

Print the intervals after overlapping in sorted manner.  There should be a newline at the end of output of every test case.

Constraints:

1 ≤ T ≤ 50
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 100


Example:

Input
2
4
1 3 2 4 6 8 9 10
4
6 8 1 9 2 4 4 7

Output
1 4 6 8 9 10
1 9

Algorithm:


  ****/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//code
	struct Interval
	{
	    int s, e;
	    Interval(int a, int b) : s(a), e(b)
	    {}
	};
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<Interval> intervals;
	    for(int i=0; i<n; i++) {
	        int s, e;
	        cin >> s >> e;
	        Interval in(s, e);
	        intervals.push_back(in);
	    }

	    //sort vector (nlogn)
	    sort(intervals.begin(), intervals.end(), [](Interval in1, Interval in2)
	    {
	        if(in1.s != in2.s)
    	        return in1.s < in2.s;
    	    return in1.e < in2.e;
	    });

	    int i=0, j=1;
	    for(; j<intervals.size(); j++) {
	        //cout << in.s << ", "<< in.e << endl;
	        if(intervals[j].s <= intervals[i].e) { //merge
	            intervals[i].e = max(intervals[i].e, intervals[j].e);
	        }
	        else {
	            i++;
	            intervals[i]=intervals[j];
	        }
	    }
	    for(int k=0; k<=i; k++)
	        cout << intervals[k].s << " " << intervals[k].e << " ";
	    cout << endl;
	}
	return 0;
}

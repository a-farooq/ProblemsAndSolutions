/****
Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. First line is N number of activities then second line contains N numbers which are starting time of activies.Third line contains N finishing time of activities.

Output:
For each test case, output a single number denoting maximum activites which can be performed in new line.

Constraints:
1<=T<=50
1<=N<=1000
1<=A[i]<=100

Example:
Input:
2
6
1 3 2 5 8 5
2 4 6 7 9 9
4
1 3 2 5
2 4 3 6

Output:
4
4

Explanation:
Test Case 1: The following activities can be performed (in the same order):
(1, 2)
(3, 4)
(5, 7)
(8, 9)
****/
#include <iostream>
#include <algorithm>
using namespace std;

struct meeting
{
    int start;
    int end;
};
	
bool compare(meeting a, meeting b)
{
    if(a.end != b.end)
        return a.end < b.end;
    return a.start <= b.start;
}

int main() {
	//code
	
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    //vector<meeting> meet;
	    meeting meet[n];
	    //pair<int, int> meet[n];
	    
	    for(int i = 0; i < n; i++)
	        cin >> meet[i].start;
	    
	    for(int i = 0; i < n; i++)
	        cin >> meet[i].end;
        
        sort(meet, meet+n, compare);
        
        int last_end = 0;
        int count = 0;
        for(auto t : meet) {
            if(t.start >= last_end) {
                last_end = t.end;
                count++;
            }
        }
        cout << count << endl;
	}
	return 0;
}

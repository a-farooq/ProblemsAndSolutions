/****
Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave on the same day. Also, arrival and departure times will not be same for a train, but we can have arrival time of one train equal to departure of the other. In such cases, we need different platforms, i.e at any given instance of time, same platform can not be used for both departure of a train and arrival of another.

Input:
The first line of input contains T, the number of test cases. For each test case, first line will contain an integer N, the number of trains. Next two lines will consist of N space separated time intervals denoting arrival and departure times respectively.
Note: Time intervals are in the 24-hour format(hhmm),  of the for HHMM , where the first two charcters represent hour (between 00 to 23 ) and last two characters represent minutes (between 00 to 59).

Output:
For each test case, print the minimum number of platforms required for the trains to arrive and depart safely.

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= A[i] < D[i] <= 2359

Example:
Input:
2
6 
0900  0940 0950  1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240 

Output:
3
1

Explanation:
Testcase 1: Minimum 3 platforms are required to safely arrive and depart all trains.

Algorithm:
1.The idea is to consider all events in sorted order. Once we have all events in sorted order, we can trace the number of trains at any time keeping track of trains that have arrived, but not departed.

2.To be more precise it will be useful to make multimap to store all arrival and departure times in it. The first value of element in multimap tells the arrival/departure time and second value tells whether it’s arrival or departure represented by ‘a’ or ‘d’ respectively.
If its arrival then do increment by 1 otherwise decrease value by 1.

3. Step1: create multimap
    Step2: store all arrival & departure times in it.
    Step3: Traverse map and if second value of map is 'a' then platform required will increment by 1, otherwise decrement by 1.
    Step4: keep update the maximum platform needed after each inc/dec operations.
  ****/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    multimap<int, char> timings;
	    for(int i=0; i<n; i++) {
	        int val;
	        cin >> val;
	        timings.emplace(val, 'a');
	    }
	    for(int i=0; i<n; i++) {
	        int val;
	        cin >> val;
	        timings.emplace(val, 'd');
	    }
	    auto it = timings.begin();
	    int platforms=0;
	    int res = 0;
	    while(it != timings.end()) {
	        if(it->second == 'a')
	            platforms++;
	        else platforms--;

	        it++;
	        res = max(res, platforms);
	    }
	    cout << res << endl;
	}
	return 0;
}

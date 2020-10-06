/****
Consider a big party where a log register for guest’s entry and exit times is maintained. Find the time at which there are maximum guests at the party. Note that entries in the register are not in any order.  if two events have the same time, then arrival is preferred over the exit.



Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the entry and exit array. Then the next two lines contains the entry and exit array respectively.

Output:
Print the maximum no of guests and the time at which there are maximum guests at the party.

Constraints:
1<=T<=10^5
1<=N<=10^5
1<=entry[i],exit[i]<=10^5

Example:
Input:
2
5
1 2 10 5 5
4 5 12 9 12
7
13 28 29 14 40 17 3 
107 95 111 105 70 127 74 

Output:
3 5
7 40

algoithm:
similar to minimum platforms problem
  ****/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int in[n];
        int out[n];
        for(int i=0; i<n; i++)
            cin >> in[i];
        for(int i=0; i<n; i++)
            cin >> out[i];

        sort(in, in+n);
        sort(out, out+n);

        int i=0, j=0, guests=0, tim=0, res=0;
        //iterate over both the sorted arrays
        //increment guest count if in time is found
        //decrement guest count if out time is found
        while(i<n && j<n)
        {
            if(in[i] <= out[j]) {
                guests++;
                if(res < guests) {
                    res = guests;
                    tim = in[i];
                }
                i++;
            }
            else {
                j++; guests--;
            }

            //cout << res << " " << t << endl;
        }
        cout << res << " " << tim << endl;
        /*
        multimap<int, char> timings;
        for(int i=0; i<n; i++) {
            int val;
            cin >> val;
            timings.emplace(val, 'e');
        }
        for(int i=0; i<n; i++) {
            int val;
            cin >> val;
            timings.emplace(val, 'x');
        }
        auto it = timings.begin();
        int guests=0;
        int res = 0;
        int tim = 0;
        while(it != timings.end()) {
            if(it->second == 'e')
                guests++;
            else guests--;

            if(res <= guests) {
                res = guests;
                tim = it->first;
            }
            it++;
        }
        cout << res << " " << tim << endl;
        */
    }

	return 0;
}

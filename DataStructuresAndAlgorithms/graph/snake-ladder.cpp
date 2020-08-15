/****
Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

Example
For the above board output will be 3
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

Output:
3
1

Explanation:
Testcase 1:
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
****/

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 30
/*
struct SnakeLadder{
    int start, end;
    SnakeLadder(int x, int y) : start(x), end(y)
    {}

};

inline bool operator < (const SnakeLadder& lhs, const SnakeLadder& rhs)
{
    return lhs.start < rhs.start;
}

set<struct SnakeLadder> sl_set;

int compare (pair<int,int> const& p1, pair<int,int> const& p2)
{
    return p1.first < p2.first;
}
*/
map<int, int> pairmap;
int min_moves = MAX;

void snakeladder(int p, int moves)
{
    if(moves > min_moves) return;

    if(p >= MAX) {
        min_moves = moves < min_moves ? moves : min_moves;
        return;
    }

    auto it = pairmap.find(p);
    if(it != pairmap.end()) {
        if(it->second < p) return;
        p = it->second;
    }

    if(p >= MAX) {
        min_moves = moves < min_moves ? moves : min_moves;
        return;
    }

    snakeladder(p+6, moves+1);
    snakeladder(p+5, moves+1);
    snakeladder(p+4, moves+1);
    snakeladder(p+3, moves+1);
    snakeladder(p+2, moves+1);
    snakeladder(p+1, moves+1);

    return;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    //sl_set.clear();
	    //vector<pair<int, int>> pairlist;
	    pairmap.clear();
	    min_moves = MAX;
	    int n, x, y;
	    cin >> n;
	    for(int i = 0; i < n; i++) {
	        cin >> x >> y;
	        //SnakeLadder sl(x, y);
	        //sl_set.insert(sl);
	        //pairlist.push_back(make_pair(x, y));
	        pairmap.emplace(x, y);
	    }

	    //for(auto p : pairlist) cout << p.first << " " << p.second << endl;
	    //sort(pairlist.begin(), pairlist.end(), compare);
	    //for_each(pairlist.begin(), pairlist.end(), [](pair<int, int>p1, pair<int, int>p2){ return p1.first < p2.first; });
	    //for(auto p : pairmap) cout << p.first << " " << p.second << endl;

	    //for(auto iter : sl_set) {
	    //    cout << iter.start << " " << iter.end << endl;
	    //}
	    //auto iter = sl_set.find(SnakeLadder)

	    snakeladder(1, 0);
	    cout << min_moves << endl;
	}
	return 0;
}

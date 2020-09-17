/****
Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

Note: No two strings are the second most repeated, there will be always a single string.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings in a sequence and the second line contains N space separated strings.

Output:
For each test case, in a new line print the second most repeated string.

Constraints:
1<=T<=100
3<=N<=10^3
1<=|String length|<=100

Example:
Input:
2
6
aaa bbb ccc bbb aaa  aaa
6
geeks for geeks for geeks aaa

Output:
bbb
for
  ****/

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    unordered_map<string, int> mp;
	    map<int, string> mmap;
	    vector<pair<int, string>> vec;
	    int n;
	    cin >> n;
	    while(n--) {
	        string st;
	        cin >> st;
	        mp[st]++;
	    }
	    //sorting a map over the values
	    for(auto it : mp) {
	        //cout << it.first << ", "<< it.second<< endl;
	        //mmap.emplace(it.second, it.first);
	        vec.push_back(make_pair(it.second, it.first));
	    }
	    sort(vec.begin(), vec.end(), [](pair<int,string> &a, pair<int,string>&b){ return a.first > b.first; });
	    /*
	    for(auto it : vec) {
	        cout << it.first << ", "<< it.second<< endl;
	        //mmap.emplace(it.second, it.first);
	    }
	    */
	    cout << vec[1].second << endl;
	}
	return 0;
}

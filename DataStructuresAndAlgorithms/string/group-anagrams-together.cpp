/****
Given an array of words, print the count of all anagrams together in sorted order (increasing order of counts).
For example, if the given array is {“cat”, “dog”, “tac”, “god”, “act”}, then grouped anagrams are “(dog, god) (cat, tac, act)”. So the output will be 2 3.

Input:
First line consists of T test case. First line of every test case consists of N, denoting the number of words in array. Second line of every test case consists of words of array.

Output:
Single line output, print the counts of anagrams in increasing order.

Constraints:
1<=T<=100
1<=N<=50

Example:
Input:
2
5
act cat tac god dog
3
act cat tac
Output:
2 3
3
  ****/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    string st;
	    unordered_map<string, int> umap;
	    cin >> n;
	    for(int i=0; i<n; i++) {
	        cin >> st;
	        sort(st.begin(), st.end());
	        //cout << st << endl;
	        umap[st]++;
	    }

	    vector<int> res;
	    for(auto iter:umap) {
	        res.push_back(iter.second);
	        //cout << iter.first<<"=>"<<iter.second<<endl;
	    }
	    sort(res.begin(), res.end());
	    for(auto val : res) cout << val << " "; cout << endl;
	}
	return 0;
}

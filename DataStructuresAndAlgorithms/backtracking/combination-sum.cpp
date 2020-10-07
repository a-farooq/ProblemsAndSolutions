/****
Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. The same repeated number may be chosen from A unlimited number of times.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines of input, first of which contains N, size of array. Next line contains N space seperated integers, and the last line contains B.

Output:
For each testcase, print the sets enclosing a backet "(" and ")". No space between two sets. If no set can be formed with the given set, then print "Empty" (without quotes).

Constraints:
1 <= T <= 500
1 <= N <= 12
1 <= A[i] <= 9
1 <= B <= 30

Example:
Input:
3
4
7 2 6 5
16
11
6 5 7 1 8 2 9 9 7 7 9
6
4
2 4 6 8
8

Output:
(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)
(1 1 1 1 1 1)(1 1 1 1 2)(1 1 2 2)(1 5)(2 2 2)(6)
(2, 2, 2, 2)(2, 2, 4)(2, 6)(4, 4)(8)

Explanation:
Testcase 1: Required sets with sum equal to B (8) are as follows:
[2, 2, 2, 2]
[2, 2, 4]
[2, 6]
[4, 4]
[8]
  ****/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool found = false;
bool comb_sum(int* a, int i, int n, int sum, int k, vector<int> res)
{
    while(i < n)
    {
        if(sum==k) {
            cout << "(";
            int j=0;
            for(; j<res.size()-1; j++)
                cout << res[j] << " ";
            cout << res[j]<<")";
            found = true;
            return true;
        }
        else if(sum < k) {
            res.push_back(a[i]);
            comb_sum(a, i, n, sum+a[i], k, res);
            res.pop_back();
        }
        //else return false;

        i++;
    }

    /*
    if(i>=n) {
        return;
    }
    if(sum==k) {
        cout << "(";
        for(auto val:res)
            cout << val << " ";
        cout << ")";
        return;
    }
    if(sum>k) {
        return;
    }
    res.push_back(a[i]);
    comb_sum(a, i, n, sum+a[i], k, res);
    comb_sum(a, i+1, n, sum+a[i+1], k, res);
    */
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    set<int> hset;
	    cin >> n;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];
	    cin >> k;

	    //sort(a, a+n);
	    //sort and remove duplicates
	    for(auto val:a)
	        hset.insert(val);

	    int i=0;
	    for(auto it: hset) {
	        a[i] = it;
	        i++;
	    }
	    vector<int> res;
	    found = false;
	    comb_sum(a, 0, i, 0, k, res);
	    if(!found) cout << "Empty";
	    cout << endl;
	}
	return 0;
}

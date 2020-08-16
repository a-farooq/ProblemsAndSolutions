/****
  Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

ach number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

Input:
First is T , no of test cases. 1<=T<=500
Every test case has three lines.
First line is N, size of array. 1<=N<=12
Second line contains N space seperated integers(x). 1<=x<=9.
Third line is the sum B. 1<=B<=30.
 
Output:
One line per test case, every subset enclosed in () and in every set intergers should be space seperated.(See example)

Example:
Input:
2
7
10 1 2 7 6 1 5
8
5
8 1 8 6 8
12

Output:
(1 1 6)(1 2 5)(1 7)(2 6)
Empty

****/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<string> res_set;

void combSum(int arr[], int n, int idx, int sum, int cur, string res)
{
    if(cur > sum) return;

    if(cur == sum) {
        sort(res.begin(), res.end(), [](const char&a, const char&b){ return a < b;});
        res_set.insert(res);
        return;
    }

    for(int i = idx+1; i < n; i++) {
        combSum(arr, n, i, sum, cur+arr[i], res+to_string(arr[i]));
    }
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    res_set.clear();
	    int n, sum;
	    cin >> n;
	    int arr[n];
	    int i = 0;
	    while(i < n) {
	        cin >> arr[i++];
	    }
	    cin >> sum;
	    combSum(arr, n, -1, sum, 0, "");
	    if(res_set.empty()) cout << "Empty" << endl;
	    else {
    	    for(string str : res_set) {
    	        //cout << str << endl;
    	        string res = "(";
    	        for(char ch : str) { res += ch; res += " "; }
    	        //rtrim(res);
    	        res = res.substr(0, res.length()-1);
    	        res += ")";
    	        cout << res;
    	    }
    	    cout << endl;
	    }
	}
	return 0;
}

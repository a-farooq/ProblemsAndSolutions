/****
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

For example:
1,2,3 → 1,3,2
3,2,1 → 1,2,3

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the array of next permutation in a separate line.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100

Example:
Input:
1
6
1 2 3 6 5 4

Output:
1 2 4 3 5 6
  ****/

#include <iostream>
#include <vector>
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
	    vector<int> num;
	    for(int i=0; i<n; i++) {
	        int k;
	        cin >> k;

	        num.push_back(k);
	    }
	    if(!next_permutation(num.begin(), num.end()))
	        sort(num.begin(), num.end());

	    for(auto val:num) cout << val << " "; cout << endl;
	}
	return 0;
}

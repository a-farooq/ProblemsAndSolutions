/********
Given two arrays A and B of equal size, the task is to find if given arrays are equal or not. Two arrays are said to be equal if both of them contain same set of elements, arrangements (or permutation) of elements may be different though.
Note : If there are repetitions, then counts of repeated elements must also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  Each test case contains 3 lines of input. The first line contains an integer N denoting the size of the array. The second line contains element of array A[]. The third line contains elements of the array B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N). 

Constraints:
1 <= T <= 100
1 <= N <= 10ˆ7
1 <= A[],B[] <= 10ˆ18
Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15
Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1}; Since all the array elements are same. So,
Output : 1
Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15}; Since all the array elements are not same. So,
Output : 0
********/

#include <iostream>
#include <set>

using namespace std;

multiset<unsigned> hset;

int main() {
	//code
	int t, n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    unsigned int k;
	    hset.clear();
	    for(int i = 0; i < n; i++)
	    {
	        cin >> k;
	        hset.insert(k);
	    }

	    bool flag = true;
	    for(int i = 0; i < n; i++)
	    {
	        cin >> k;
	        //if(hset.find(k) == hset.end()) flag = false;
	        //else hset.erase(k);

	        //erase with value deletes all the matching values
	        auto iter = hset.find(k);
	        if(iter != hset.end()) hset.erase(iter);
	    }

	    cout << (hset.empty() ? 1 : 0) << endl;
	}
	return 0;
}

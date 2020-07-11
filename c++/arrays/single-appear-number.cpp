/********
Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.

Input:
The first line of input consists of T, the number of the test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case contains the size of the array, and the second line has the elements of the array.

Output:
For each testcase, in a new line, print the number that appears only once in the array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^7
0 ≤ A[i] ≤ 10^17

Example:
Input:
1
11
1 1 2 2 3 3 4 50 50 65 65
Output:
4
********/


#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t, n;
    unsigned a, b;
    cin >> t;
    while(t--)
    {
        cin >> n;
        b = 0;
        for(auto i=0; i < n; i++)
        {
            cin >> a;
            b ^= a;
        }
        cout << b << endl;
    }
}
int main2() {
	//code
	int t, n;
	unsigned int a, b, res;
	set<unsigned> s;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    
	    s.clear();
	    for(auto i=0; i<n; i++) {
	        cin >> a;
	        if(s.find(a)!=s.end()) s.erase(a);
	        else s.insert(a);
	    }
	    if(!s.empty()) cout << *s.begin() << endl;
	    
	}
	return 0;
}

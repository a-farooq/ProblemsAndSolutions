/********
Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.

Note: Please avoid printing the same common element more than once.

Input:
First line contains a single integer T denoting the total number of test cases. T testcases follow. Each testcase contains four lines of input. First line consists of 3 integers N1, N2 and N3, denoting the sizes of arrays A, B, C respectively. The second line contains N1 elements of A array. The third lines contains N2 elements of B array. The fourth lines contains N3 elements of C array.

Output:
For each testcase, print the common elements of array. If not possible then print -1.

Constraints:
1 <= T <= 100
1 <= N1, N2, N3 <= 10ˆ7
1 <= Ai, Bi, Ci <= 10ˆ18

Example:
Input:
1
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
Output:
20 80

Explanation:
Testcase1:  20 and 80 are the only common elements


********/
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n1, n2, n3, k;
	    cin >> n1 >> n2 >> n3;

	    set<int> set1, set2;
	    for(int i = 0; i < n1; i++) {
	        cin >> k;
	        set1.insert(k);
	    }

	    for(int i = 0; i < n2; i++) {
	        cin >> k;
	        auto iter = set1.find(k);
	        if(iter != set1.end())
	            set2.insert(k);
	    }
	    set1.clear();

	    for(int i = 0; i < n3; i++) {
	        cin >> k;
	        auto iter = set2.find(k);
	        if(iter != set2.end())
	            set1.insert(k);
	    }

	    if(set1.empty()) cout << -1;
	    else
	    for(auto k : set1)
	        cout << k << " ";
	    cout << endl;
	}
	return 0;
}

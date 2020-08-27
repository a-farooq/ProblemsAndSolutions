/****
Given two sorted arrays, we can get a set of sums(add one element from the first and one from second). Find the N’th element in the set considered in sorted order.
Note: Set of sums should have unique elements.

Input : arr1[] = {1, 2}
        arr2[] = {3, 4}
        N = 3
Output : 6
We get following elements set of sums.
4(1+3), 5(2+3 or 1+4), 6(2+4)
Third element in above set is 6.

Input : arr1[] = {1, 3, 4, 8, 10} 
        arr2[] = {20, 22, 30, 40} 
        N = 4
Output : 25
We get following elements set of sums.
21(1+20), 23(1+22 or 20+3), 24(20+4), 25(22+3)...
Fourth element is 25.
Input:
The first line of input contains an integer T denoting tghe number of test cases. Then T test cases follow. Each test case contains two integers m and n denoting the size of the two arrays respectively. The next two lines contains m and n space separated elements forming both the arrays respectively. The last line contains the value of N.

Output:
Print the value of Nth element in set. If Nth element doesn't exist in set print -1.

Constraints:
1<=T<=100
1<=m,n<=10^4
1<=arr1[i],arr2[j]<=10^4
1<=N<=m*n

Example:
Input:
2
2 2
1 2
3 4
3
5 4
1 3 4 8 10
20 22 30 40
4

Output:
6
25
  ****/

#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
    {
        set<int> sumset;
        int m, n;
        cin >> m >> n;
        int a[m], b[n];
        for(int i = 0; i < m; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int k;
        cin >> k;

        /*
        //priority queue inserts duplicates too
        priority_queue<int> maxheap;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = a[i]+b[j];
                cout << "sum: " << sum << endl;
                if(maxheap.size() >= k) {
                    if(sum < maxheap.top()) {
                        maxheap.pop();
                        maxheap.push(sum);
                    }
                }
                else maxheap.push(sum);
                cout << "top: " << maxheap.top() << endl;
            }
        }
        cout << maxheap.top() << endl;*/

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                sumset.insert(a[i]+b[j]);
            }
        }

        vector<int> vec(sumset.begin(), sumset.end());
        cout << vec[k-1] << endl;
        //for(int val : sumset) cout << val << " ";
        //cout << endl;
    }
    return 0;
}

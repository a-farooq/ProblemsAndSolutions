/****
Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer N denoting the size of array and the size of subarray K. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum for every subarray of size k.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 10^7
1 ≤ K ≤ N
0 ≤ A[i] <= 10^7

Example:
Input:
2
9 3
1 2 3 1 4 5 2 3 6
10 4
8 5 10 7 9 4 15 12 90 13

Output:
3 3 4 5 5 5 6
10 10 10 15 15 90 90

Explanation:
Testcase 1: Starting from first subarray of size k = 3, we have 3 as maximum. Moving the window forward, maximum element are as 3, 4, 5, 5, 5 and 6.


  ****/

#include <iostream>
#include <map>
#include <deque>
using namespace std;

void sliding_window_deque(int*a, int n, int k)
{
	deque<int> dq;

	for(int i=0; i < k; i++) {
	    while(!dq.empty() && a[i]>=a[dq.back()])
	        dq.pop_back();

	    dq.push_back(i);
	}
	cout << a[dq.front()] << " ";

	for(int j=k; j< n; j++) {


	    while(!dq.empty() && dq.front()<=j-k)
	        dq.pop_front();

	    while(!dq.empty() && a[j]>=a[dq.back()])
            dq.pop_back();

	    dq.push_back(j);
	    cout << a[dq.front()] << " ";// << endl;
	    //cout << "size: " << mp.size() << endl;
	}
	//cout << a[dq.front()] << " ";
	cout << endl;

}

void sliding_window_map(int*a, int n, int k)
{
	map<int,int> mp;

	for(int i=0; i < k; i++) {
	    mp[a[i]]++;
	}
	cout << mp.rbegin()->first << " ";

	int i = 0;
	for(int j=k; j< n; j++) {
	    mp[a[i]]--;
	    if(mp[a[i]]==0) mp.erase(a[i]);

	    mp[a[j]]++;
	    i++;
	    cout << mp.rbegin()->first << " ";
	    //cout << "size: " << mp.size() << endl;
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {

	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i=0; i<n; i++) cin >> a[i];
		
		//two methods
		sliding_window_deque(a, n, k); //O(n)
		//sliding_window_map(a, n, k); //O(nlogk)
	}
	return 0;
}

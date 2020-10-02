/****
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
Note: Expected solution in O(n) time using constant extra space.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

Output:
Single line output, print the smallest positive number missing.

Constraints:
1 <= T <= 100
1 <= N <= 10^6
-10^6 <= arr[i] <= 10^6

Example:
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2

Explanation:
Testcase 1: Smallest positive missing number is 6.
Testcase 2: Smallest positive missing number is 2.

Algorithm:
insert all positive numbers into a set
find each number starting from 1 till the max+1 inserted
if a number is not found, this is the answer
  ****/

#include <iostream>
#include <unordered_set>
using namespace std;

// Functio to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n) {

    // Your code here
    sort(arr, arr+n);
    //for(int i=0; i<n; i++) cout << arr[i] << " "; cout << endl;

    int i=0;
    for(; i<n; i++)
        if(arr[i]>0)
            break;

    if(i==n) return 1;

    int k=0;
    int j=i;
	//array can have duplicates
    for(; j<n; j++) {
        if(arr[j]>k) {
            if(arr[j] > ++k)
                break;
        }
        /*
        if(arr[j]==k+1)
            k++;
        else if(arr[j] != k)
            break;*/
    }
    //return k+1;
    return j==n?k+1:k;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    int maxi = 0;
	    unordered_set<int> uset;
	    cin >> n;
	    for(int i=0; i<n; i++) {
	        int m;
	        cin >> m;
	        if(m>0)
	            uset.insert(m);
	        maxi = max(maxi, m);
	    }

	    int i=1;
	    for(; i<=maxi+1; i++)
	    {
	        if(uset.find(i) == uset.end()) {
	            break;
	        }
	    }
	    cout << i << endl;
	}
	return 0;
}

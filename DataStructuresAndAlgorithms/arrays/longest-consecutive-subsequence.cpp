/****
Given an array A of integers. The task is to complete the function which returns an integer denoting the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N. Then in the next line are N space separated values of the array A.

Output:
For each test case in a new line output will be the length of the longest consecutive increasing sub-sequence present in the array A[ ].

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Ai <= 10^8

Example(To be used only for expected output):
Input:
2
7
1 9 3 10 4 20 2
11
36 41 56 35 44 33 34 92 43 32 42
Output:
4
5
Explanation:
Testcase 1: Logest consecutive subsequence is 1, 2, 3, 4 of length 4.

Algorithm:

Create an empty hash.
Insert all array elements to hash.
Do following for every element arr[i]
Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
If this element is the first element, then count the number of elements in the consecutive starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
If the count is more than the previous longest subsequence found, then update this.
****/

// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int a[], int n)
{
    unordered_set<int> uset;

    for(int i=0; i<n; i++)
        uset.insert(a[i]);

    int maxi = 0;
    for(int i=0; i<n; i++) {
        if(uset.find(a[i]-1) == uset.end()) { //a[i] is smallest of subsequence
            int k = a[i]+1;
            int cnt = 1;
            while(uset.find(k) != uset.end()) { //next consecutive number found
                cnt++;
                k++;
            }
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}

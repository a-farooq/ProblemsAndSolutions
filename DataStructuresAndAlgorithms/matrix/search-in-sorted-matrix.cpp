/****
Given a matrix mat[] of size n x m, where every row and column is sorted in increasing order, and a number x is given. The task is to find whether element x is present in the matrix or not.

Expected Time Complexity : O(m + n)

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case consist of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a single integer x, the element to be searched.

Output:
Corresponding to each test case, print in a new line, 1 if the element x is present in the matrix, otherwise simply print 0.

Constraints:
1 <= T <= 200
1 <= N, M <= 30
1 <= mat[][] <= 100
1<= X <= 100
Example:
Input:
2
3 3
3 30 38 44 52 54 57 60 69
62
1 6
18 21 27 38 55 67
55

Output:
0
1

Explanation:
Testcase 1: 62 is not present in the matrix, so output is 0.
Testcase 2: 55 is present in the matrix at 5th cell.

  ****/

#include <iostream>
using namespace std;

void print(int *a, int l, int r)
{
    for(int i=l; i<=r; i++) cout << a[i] << " "; cout << endl;
}

bool binary_search(int *a, int l, int r, int key)
{
    //int mid = -1;
    //print(a, l, r);
    while(l<=r) {
        int mid = l+(r-l)/2;

        //cout << l <<", "<<mid<<", "<<r<<endl;

        if(a[mid]==key) return true;

        else if(a[mid]<key) l = mid+1;

        else r = mid-1;
    }

    return false;
}

bool binary_search_rec(int *a, int l, int r, int key)
{
    if(l<=r) {
        int mid = l+(r-l)/2;
        if(a[mid]==key) return true;

        else if(a[mid]<key) return binary_search_rec(a, mid+1, r, key);

        else return binary_search_rec(a, l, mid-1, key);
    }
    return false;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int r, c, key;
	    cin >> r >> c;
	    int mat[r][c];
	    for(int i=0; i<r; i++)
	        for(int j=0; j<c; j++)
	            cin >> mat[i][j];
	    cin >> key;

	    bool found = false;
	    for(int i=0; i<r; i++) {
	        if(mat[i][c-1]>=key) {
	            bool ret = binary_search_rec(mat[i], 0, c-1, key);
	            if(ret) { found = true; break; }
	        }
	    }
	    cout << (found?1:0) << endl;
	}
	return 0;
}

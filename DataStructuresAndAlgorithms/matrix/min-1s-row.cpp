/****
Determine the row index with minimum number of ones. The given 2D matrix has only zeroes and ones and also the matrix is sorted row wise. If two or more rows have same number of 1's than print the row with smallest index.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of two integer n and m. The next line consists of n*m spaced integers. 

Output:
Print the index of the row with minimum number of 1's. If there is 0 number of '1' in the matrix then, print '-1'.

Constraints: 
1 <= T <= 103
1 <= n, m <= 100

Example:
Input:
2
3 3
0 0 0 0 0 0 0 0 0
4 4
0 0 0 1 0 1 1 1 0 0 1 1 0 0 1 1
3 3
0 0 0 0 0 0 0 0 1
Output:
-1
0
2

Explanation:
Testcase 2: The matrix formed for the given input will be as such
0 0 0 1
0 1 1 1
0 0 1 1
0 0 1 1
First row is having minimum number of 1 i.e. answer is 0.

  ****/

#include <iostream>
using namespace std;

int binary_search(int* a, int l, int r)
{
    if(a[0]==1)
        return 0;
    if(a[r]==0)
        return r+1;

    while(l<r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==0) {
            if(a[mid+1]==1)
                return mid+1;
            else l=mid;
        }
        else {
            if(a[mid-1]==0)
                return mid;
            else r=mid;
        }
    }
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    int a[m][n];
	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++)
	            cin >> a[i][j];

	    int res_idx = 0;
	    int i=0;
	    for(; i<m; i++)
	        if(a[i][n-1]==1)
	            break;

	    if(i==m) {
	        //all 0s in the matrix
	        res_idx=-1;
	    }
	    else {
	        //row i is first row that has at least one 1
	        //find the index of left most 1 at index i
	        int j=binary_search(a[i], 0, n-1);

	        //climb down each row at col j
	        //if it has 0 at col j and it is not all 0s
	        //then the row has fewer 1s
	        for(int k=i; k<m; k++) {
	            if(a[k][j]==0 && a[k][n-1]!=0) {
	                j=binary_search(a[k], j, n-1);
	                res_idx=k;
	            }
	        }
	    }

	    cout << res_idx << endl;
	}
	return 0;
}

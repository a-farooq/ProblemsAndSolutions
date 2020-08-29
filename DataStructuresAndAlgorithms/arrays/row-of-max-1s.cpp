/****
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s.

Example
Input matrix
0 1 1 1
0 0 1 1
1 1 1 1  // this row has maximum 1s
0 0 0 0

Output: 2

Input:
The first line of input is an integer T denoting the no of test cases.Then T test cases follow. Each test case consists of 2 lines . The first line of each test case is are two integers row and col denoting the no of rows and columns of matrix . Then in the next line are row*col space separated values of the matrix M.

Output:
For each test case in a new line print the required first row index .

Constraints:
1<=T<=20
1<=row,col<=40
0<=M[ ][ ]<=1

Example:
Input:
2
3 4
0 1 1 1 0 0 1 1 0 0 1 1
2 2
0 1 1 1
 
Output:
0
1
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    //without saving into a matrix
	    int m, n, k;
	    int maxi = 0, ind;
	    cin >> m >> n;
	    for(int i = 0; i < m; i++) {
	        bool flag = false;
	        for(int j = 0; j < n; j++) {
	            cin >> k;
				//just cheking the left most 1 since each row is sorted
	            if(k && !flag) {
	                flag = true;
	                if(maxi < n-j) {
	                    ind = i;
	                    maxi = n-j;
	                }
	            }
	        }
	    }
	    /*
	    int a[m][n];
	    for(int i = 0; i < m; i++)
	        for(int j = 0; j < n; j++)
	            cin >> a[i][j];

	    int cnt = 0, ind = 0;
	    for(int i = n-1; i >= 0; i--) {
	        if(a[0][i]) cnt++;
	        else break;
	    }

	    if(cnt != n) {
    	    int j = n-cnt-1;
    	    for(int i = 1; i < m; i++) {
    	        while(j >= 0 && a[i][j]) { j--; ind = i; }
    	        if(j<0) break;
    	    }
	    }
	    */
	    cout << ind << endl;
	}
	return 0;
}

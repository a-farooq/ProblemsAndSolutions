/****
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Example:
Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0

Explanation:
Testcase1: Since only first element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.

  ****/


#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int r, c;
	    cin >> r >> c;
	    int mat[r][c];
	    for(int i=0; i < r; i++)
	        for(int j=0; j<c; j++) {
	            cin >> mat[i][j];
	            if(mat[i][j]) {
	                mat[0][j]=1;
	                mat[i][0]=1;
	            }
	        }

	    //not processing the top row now but after cols processing
	    //o/w whole matrix will be 1 if mat[0][0]=1 and process top row now
	    for(int i=1; i < r; i++) {
	        if(mat[i][0]) {
	            for(int j=0; j<c; j++) {
	                mat[i][j]=1;
	            }
	        }
	    }

	    //hold the original state of mat[0][0] to be used later
	    int flag = mat[0][0];

	    for(int j=0; j < c; j++) {
	        if(mat[0][j]) {
	            for(int i=0; i<r; i++) {
	                mat[i][j]=1;
	            }
	        }
	    }

	    if(mat[0][0] && flag)
	        for(int j=0; j<c; j++)
	            mat[0][j]=1;

	    for(int i=0; i < r; i++) {
	        for(int j=0; j < c; j++)
	            cout << mat[i][j] << " ";
	        cout <<endl;
	    }
	}
	return 0;
}

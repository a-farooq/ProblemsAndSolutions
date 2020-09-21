/****
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (mat[][]). The task to print a solved Sudoku. For simplicity you may assume that there will be only one unique solution.

Sample Sudoku for you to get the logic for its solution:



Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.

Output:
For each test case, in a new line, print the space separated values of the solution of the the sudoku.

Constraints:
1 <= T <= 10
0 <= mat[] <= 9

Example:
Input:
1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

Output:
3 1 6 5 7 8 4 9 2 5 2 9 1 3 4 7 6 8 4 8 7 6 2 9 5 3 1 2 6 3 4 1 5 9 8 7 9 7 4 8 6 3 1 2 5 8 5 1 7 9 2 6 4 3 1 3 8 9 4 7 2 5 6 6 9 2 3 5 1 8 7 4 7 4 5 2 8 6 3 1 9

Explanation:
Testcase 1: The solved sudoku is:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

Solution:
Like all other Backtracking problems, we can solve Sudoku by one by one assigning numbers to empty cells. Before assigning a number, we check whether it is safe to assign. We basically check that the same number is not present in the current row, current column and current 3 x 3 subgrid. After checking for safety, we assign the number, and recursively check whether this assignment leads to a solution or not. If the assignment doesn’t lead to a solution, then we try next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, we return false.

  Find row, col of an unassigned cell
  If there is none, return true
  For digits from 1 to 9
    a) If there is no conflict for digit at row, col
        assign digit to row, col and recursively try fill in rest of grid
    b) If recursion successful, return true
    c) Else, remove digit and try another
  If all digits have been tried and nothing worked, return false

  ****/

#include <iostream>
using namespace std;

bool check(int sudoku[9][9], int num, int x, int y)
{
    //check row
    for(int j=0; j<9; j++) {
        if(sudoku[x][j]==num)
            return false;
    }
    //check col
    for(int i=0; i<9; i++) {
        if(sudoku[i][y]==num)
            return false;
    }
    //check box
    int a = (x/3)*3;
    int b = (y/3)*3;
    for(int i=a; i<a+3; i++) {
        for(int j=b; j<b+3; j++) {
            if(sudoku[i][j]==num)
                return false;
        }
    }
    return true;
}

bool dfs_fill(int sudoku[9][9], int k)
{
    bool ret = false;
    int i=k/9;
    int j=k%9;

    if(k==81) return true;
    int val = sudoku[i][j];

    if(sudoku[i][j]==0) {
        for(int num=1; num<=9; num++) {
            if(check(sudoku, num, i, j)) {
                sudoku[i][j]=num;
                ret = dfs_fill(sudoku, k+1);
                if(ret) return ret;
            }
        }
    }
    else {
        ret = dfs_fill(sudoku, k+1);
        if(ret) return ret;
    }
    sudoku[i][j]=val;
    return ret;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int sudoku[9][9];
	    for(int i=0; i<9; i++)
	        for(int j=0; j<9; j++)
	            cin >> sudoku[i][j];

	    bool ret = dfs_fill(sudoku, 0);

	    for(int i=0; i<9; i++)
	        for(int j=0; j<9; j++)
	            cout << sudoku[i][j] << " ";

	    cout << endl;
	}
	return 0;
}

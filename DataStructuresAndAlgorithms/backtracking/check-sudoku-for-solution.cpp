/****
Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to check if the configuration has a solution or not. 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.

Output:
For each test case in a new line print 1 if the sudoku configuration is valid else print 0.

Constraints:
1<=T<=10
0<=mat[]<=9

Example:
Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 4 3 0 7 

Output:
1
0

Solution:
Same as solve-sudoku.cpp
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
	    cout << (ret?1:0) << endl;
	    /*
	    for(int i=0; i<9; i++)
	        for(int j=0; j<9; j++)
	            cout << sudoku[i][j] << " ";
	    cout << endl;
	    */
	}
	return 0;
}

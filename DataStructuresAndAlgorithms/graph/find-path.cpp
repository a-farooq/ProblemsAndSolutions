/****
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

 

Input:
The first line of input is an integer T denoting the no of testcases. Then T test cases follow. Each test case consists of 2 lines. The first line of each test case contains an integer N denoting the size of the square matrix. Then in the next line are N*N space separated values of the matrix (M).

Output:
For each test case in a new line print 1 if the path exist from source to destination else print 0.

Constraints:
1 <= T <= 20
1 <= N <= 20

Example:
Input:
2
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3
3
0 3 2 3 0 0 1 0 0

Output:
1
0

Explanation:
Testcase 1: The matrix for the above given input is:
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3
From the matrix we can see that there exists a path from to reach destination 2 from source 1.
Testcase 2: The matrix for the above given input is:
0 3 2
3 0 0
1 0 0
From the matrix we can see that there does not exists any path to reach destination 2 from source 1.
  ****/

#include <iostream>
using namespace std;
#define SIZE 20

bool pathDFS(int a[SIZE][SIZE], int n, int i, int j)
{
    //int ret = 0;

    if(i < 0 || j < 0 || i == n || j == n || a[i][j] == 0 || a[i][j] == 1 || a[i][j] == 4)
        return false;

    if(a[i][j] == 2) return true;

    a[i][j] = 4; //visited

    if(pathDFS(a, n, i, j+1)) return true;
    if(pathDFS(a, n, i+1, j)) return true;
    if(pathDFS(a, n, i, j-1)) return true;
    if(pathDFS(a, n, i-1, j)) return true;

    //a[i][j] = 3;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n, x, y;
	    cin >> n;
	    int a[SIZE][SIZE];

	    for(int i=0; i < n; i++)
	        for(int j = 0; j < n; j++) {
	            cin >> a[i][j];
	            if(a[i][j] == 1) {
	                x = i, y = j;
	            }
	        }

	    bool ret = pathDFS(a, n, x, y+1) || pathDFS(a, n, x+1, y) || pathDFS(a, n, x, y-1) || pathDFS(a, n, x-1, y);
	    cout << (ret ? 1 : 0) << endl;
	}
	return 0;
}

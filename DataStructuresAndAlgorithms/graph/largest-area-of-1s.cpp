/****
Given a Matrix containing 0s and 1s. Find the unit area of the largest region of 1s (refer Your Task for complete details).

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers N and M. Then in the next line are the nxm inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findArea() which takes the number of rows N, the number of columns M and the matrix A, as inputs and returns the unit area of the largest region of connected 1s.
Each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two filled cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Expected Time Complexity: O(N*M).
Expected Auxiliary Space: O(N*M).

Constraints:
1 <= T <= 100
1 <= N, M <= 100
0 <= A[ ][ ] <= 1
Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with a total 4 1s (colored in Red).
Testcase 2: Matrix can be shown as follows:
1 1 1
Largest region of 1s in the above matrix is with a total of 3 1s (colored in Red).
  ****/

#include <iostream>
using namespace std;

#define SIZE 100

void DFS(int A[SIZE][SIZE], int N, int M, int i, int j, int& count)
{
    if(i < 0 || j < 0 || i == N || j == M || A[i][j] == 0 || A[i][j] == 2)
        return;

    count++;

    A[i][j] = 2;

    DFS(A, N, M, i, j+1, count);
    DFS(A, N, M, i+1, j+1, count);
    DFS(A, N, M, i+1, j, count);
    DFS(A, N, M, i+1, j-1, count);
    DFS(A, N, M, i, j-1, count);
    DFS(A, N, M, i-1, j-1, count);
    DFS(A, N, M, i-1, j, count);
    DFS(A, N, M, i-1, j+1, count);

    //A[i][j] = 1;
}
/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/
int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    // Your code here
    int maxarea = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {

            if(A[i][j] == 1) {
                int maxc = 0;
                DFS(A, N, M, i, j, maxc);
                maxarea = max(maxc, maxarea);
            }
        }
    }
    return maxarea;
    //cout << maxarea << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;

		int g[SIZE][SIZE];

		for(int i=0; i <n; i++)
			for(int j = 0; j < m; j++)
				cin >> g[i][j];

		cout << findMaxArea(n, m, g) << endl;
	}
}

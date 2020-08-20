

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

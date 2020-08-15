/****
Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 
 {{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Constraints:
1 <= T <= 100
1 <= M[][] <= 100

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4
****/  

#include <iostream>
#include<vector>
using namespace std;

void floodfill(vector<int> mat[], int i, int j, int n1, int n2, int t, int c)
{
    if(i < 0 || j < 0 || i == n1 || j == n2 || mat[i][j] != t) return;


    mat[i][j] = c;

    floodfill(mat, i, j+1, n1, n2, t, c);
    floodfill(mat, i-1, j, n1, n2, t, c);
    floodfill(mat, i, j-1, n1, n2, t, c);
    floodfill(mat, i+1, j, n1, n2, t, c);
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n1, n2, d;
	    cin >> n1 >> n2;
	    //int **mat = new int*[n2];
	    //vector<vector<int>> mat(n1, vector<int>(n2));
	    vector<int> mat[n1];
	    //int mat[n1][n2];

	    //for(int i = 0; i < n2; i++)
	    //    mat[i] = new int[n1];

	    for(int i = 0; i < n1; i++) {
	        vector<int> t(n2);
	        mat[i] = t;
	    }
	    for(int i = 0; i < n1; i++) {
	        for(int j = 0; j < n2; j++) {
	            cin >> d;
	            mat[i][j] = d;
	        }
	    }
	    /*
	    for(auto i = 0; i < n1; i++) {
	        for(auto j = 0; j < n2; j++)
	            cout << mat[i][j] << " ";
	        //cout << endl;
	    }
	    */
	    int x, y, c;
	    cin >> x >> y >> c;

	    floodfill(mat, x, y, n1, n2, mat[x][y], c);

	    for(auto i = 0; i < n1; i++)
	        for(auto j = 0; j < n2; j++)
	            cout << mat[i][j] << " ";

	    cout << endl;
	}
	return 0;
}

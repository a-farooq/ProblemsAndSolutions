/****
Given a 2D grid (G[]) of characters and a word(x), find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up, Vertically down and 4 Diagonal directions.

Example:

Input:  G[][] = {"GEEKSFORGEEKS",
                 "GEEKSQUIZGEEK",
                 "IDEQAPRACTICE"};
        x = "GEEKS"

Output: pattern found at 0, 0
        pattern found at 0, 8
        pattern found at 1, 0


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.  Each test case contains two space separated integers N and M denoting the size of the grid. Then in the next line are N * M space separated values of the grid. In the next line is the word x.

Output:
For each test case in a new line print the space separated sorted indexes of the matrix where after each index there is a ', ' . If there are no such occurences print -1.

Constraints:
1<=T<100
1<=N,M<=100
1<=G[]<=100

Example:
Input:
2
3 3
a b c d e f g h i
abc
4 3
a b a b a b e b e b e b
abe
Output:
0 0,
0 0, 0 2, 1 1,

  ****/

#include <iostream>
#include <vector>
using namespace std;

enum DIR
{
    N = 0,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
} ;

bool findstr(vector<vector<char>> a, int i, int j, int m, int n, string str, int k, DIR dir)
{
    bool ret = false;

    if(i<0 || j<0 || i==m || j==n || a[i][j]!=str[k]) return false;

    if(k == str.length()-1) return true;

    switch(dir)
    {
        case N: ret = findstr(a, i-1, j, m, n, str, k+1, dir); break;

        case NE: ret = findstr(a, i-1, j+1, m, n, str, k+1, dir); break;

        case E: ret = findstr(a, i, j+1, m, n, str, k+1, dir); break;

        case SE: ret = findstr(a, i+1, j+1, m, n, str, k+1, dir); break;

        case S: ret = findstr(a, i+1, j, m, n, str, k+1, dir); break;

        case SW: ret = findstr(a, i+1, j-1, m, n, str, k+1, dir); break;

        case W: ret = findstr(a, i, j-1, m, n, str, k+1, dir); break;

        case NW: ret = findstr(a, i-1, j-1, m, n, str, k+1, dir); break;

        default: break;
    }

    return ret;
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    //char a[m][n];
	    vector<vector<char>> a(m, vector<char>(n));
	    for(int i = 0; i < m; i++) {
	        for(int j = 0; j < n; j++) cin >> a[i][j];
	    }

	    string str;
	    cin >> str;

	    bool flag = false;
	    for(int i = 0; i < m; i++) {
	        for(int j = 0; j < n; j++) {

    	        bool res = findstr(a, i, j, m, n, str, 0, N);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, NE);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, E);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, SE);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, S);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, SW);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, W);
    	        if(!res) res = findstr(a, i, j, m, n, str, 0, NW);
    	        if(res) { cout << i << " " << j << ", "; flag = true; }
	        }
	    }
	    if(!flag) cout << -1;
	    cout << endl;
	}
	return 0;
}

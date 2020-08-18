/****
Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (n-1, n-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be travelled through.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line contains an integer N denoting the size of the square matrix. The next line contains N*N space separated values of the matrix m where 0's represents blocked paths and 1 represent valid paths.

Output:
For each test case, the output will be space separated sorted strings denoting all directions, which the rat could take to reach the destination. Print -1 if no such path exists.

User Task:
Your task is to complete the function printPath() which returns a sorted array of strings denoting all the possible paths which the rat can take to reach the destination at (n-1, n-1). If no such path exists the function should return an empty array.
Expected Time Complexity: O((Nˆ2)ˆ4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.


Constraints:
1 <= T <= 100
2 <= N <= 5
0 <= matrix[i][j] <= 1

Example
Input:
3
4
1 0 0 0 1 1 0 1 0 1 0 0 0 1 1 1
4
1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
2
1 0 1 0

Output:
DRDDRR
DDRDRR DRDDRR
-1

Explanation:
Testcase 2: The given input is in the form
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
For the above matrix the rat can reach the destination at (3, 3) from (0, 0) by two paths ie DRDDRR and DDRDRR when printed in sorted order we get DDRDRR DRDDRR.
  ****/
#include <iostream>
#include <vector>
using namespace std;
#define MAX 5

void findPath(int m[][MAX], int n, int i, int j, string res, vector<string>&vec)
{
    if(i < 0 || j < 0 || i == n || j == n || m[i][j] == 0 || m[i][j] == 2)
        return;

    //cout << i << "--" << j << "--" << res << endl;
    if(i == n-1 && j == n-1) {
        //cout << res << endl;
        vec.push_back(res);
        return;
    }

    m[i][j] = 2; //visited

    findPath(m, n, i+1, j, res+"D", vec);
    findPath(m, n, i, j+1, res+"R", vec);
    findPath(m, n, i-1, j, res+"U", vec);
    findPath(m, n, i, j-1, res+"L", vec);

    m[i][j] = 1; //backtrack
}
// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string> vec;
    //cout << n << endl;
    if(n> MAX || m[n-1][n-1]==0) {
        vec.push_back("-1");
        return vec;
    }

    //cout << "here"<< endl;
    findPath(m, n, 0, 0, "", vec);
    sort(vec.begin(), vec.end(), [&](string s1, string s2){return s1 < s2;});
    return vec;
}

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[MAX][MAX];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];

		vector<string> vec = printPath(a, n);
		for(string str : vec) cout << str << " ";
		cout << endl;
	}
}

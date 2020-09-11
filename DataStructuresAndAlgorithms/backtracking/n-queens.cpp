/****
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].
Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1.

Constraints:
1 <= T <= 10
1 <= n <= 10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]
****/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool found = false;
void print(string str)
{
    cout << "[";
    for(char ch : str) {
        cout << ch-'a' << " ";
    }
    cout << "] ";
}

void nqueens(vector<vector<int>> a, int n, int i, int j, string res)
{
    //bool ret = false;
    //cout << i << "--" << j << endl;
    if(a[i][j]) return;

    a[i][j] = 1;
    res += 'a'+j; //to_string(j);
    //cout << res << endl;

    if(i == n) {
        //cout << res << endl;
        print(res);
        found = true;
    }
    else {
		//set the column j
        for(int i2 = i; i2 <= n; i2++) 
			a[i2][j] = 1;

		//set the diagonal till right end
        for(int i2 = i, j2 = j; i2 <= n && j2 <= n; i2++, j2++)
            a[i2][j2] = 1;

		//set the diagonal till left end
        for(int i2 = i, j2 = j; i2 <= n && j2 > 0; i2++, j2--)
            a[i2][j2] = 1;

		//find next column spot in next row
        for(int j = 1; j <= n; j++)
            nqueens(a, n, i+1, j, res);
    }
    //return ret;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    //int a[10][10] = {0};
	    vector<vector<int>> a(11);
	    for(int i = 0; i < 11; i++) {
	        vector<int> t(11, 0);
	        a[i] = t;
	    }
	    //memset(a, 0, 10*10);
	    /*
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++)
	            cout << a[i][j] << " ";
	        cout << endl;
	    }*/
	    found = false;
	    for(int j = 1; j <= n; j++) {

    	    nqueens(a, n, 1, j, "");
    	    //cout << "returned"<< endl;
	    }

    	if(!found) cout << -1;
    	cout << endl;
	}
	return 0;
}

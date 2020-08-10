/******
Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7


******/

#include <iostream>
#include <cstring>
using namespace std;
int a[11][11];

int main() {
	//code
	int t, m, n;
	cin >> t;
	while(t--)
	{
	    //memset(a, 0, 11*11);
	    cin >> m >> n;
	    for(auto i = 0; i < m; i++)
	        for(auto j = 0; j < n; j++)
    	        cin >> a[i][j];
	        
	    int up = 0;
	    int down = m-1;
	    int left = 0;
	    int right = n-1;
	    
	    while(up <= down && left <= right) {
	        if(left <= right) {
        	    for(auto i = left; i <= right; i++)
        	        cout << a[up][i] << " ";
        	    up++;
	        }
	        else break;
    	    
    	    if(up <= down) {
        	    for(auto i = up; i <= down; i++)
        	        cout << a[i][right] << " ";
        	    right--;
    	    }
    	    else break;
    	    
    	    if(right >= left) {
        	    for(auto i = right; i >= left; i--)
        	        cout << a[down][i] << " ";
        	    down--;
    	    }
    	    else break;
    	    
    	    if(down >= up) {
        	    for(auto i = down; i >= up; i--)
        	        cout << a[i][left] << " ";
        	    left++;
    	    }
    	    else break;
	    }
	    cout << endl;
	}
	return 0;
}

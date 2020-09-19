/****
Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.
Note: The chess board consists of rows numbered (1 to N) and columns (1 to M).

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. Each test case contains two lines. The first line of each testcase contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For each testcase in a new line print the minimum number of moves required by the knight to go to the destination from the source. If no such move is possible print -1.

Constraints:
1 <= T <= 100
1 <= N, M <= 25

Example:
Input:
2
4 7
2 6 2 4
7 13
2 8 3 4

Output:
2
3

Explanation:
Testcase 1: One possible move for Knight is from 2, 6 to 4, 5 and then to 2, 4 which is our destination.]

Solution:
This problem can be seen as shortest path in unweighted graph. Therefore we use BFS to solve this problem. We try all 8 possible positions where a Knight can reach from its position. If reachable position is not already visited and is inside the board, we push this state into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.

Also,

Use of DFS to traverse every possible comination for the knight from xth and yth position.

Every possible position is (x+dx,x+dy).

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, 1, -1, 2, -2, 2, -2};
  ****/

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    //int a[m][n];
	    struct Cell {
	        int x, y, dist;
	        Cell(int x1, int y1, int d) : x(x1), y(y1), dist(d)
	        {}
	    };
	    int vis[m+1][n+1] = {0};
	    //for(int i=0; i<m; i++)
	    int x1, y1, x2, y2;
	    cin >> x1 >> y1 >> x2 >> y2;
	    //--x1; --y1; --x2; --y2;
	    queue<Cell> q;
	    Cell src(x1, y1, 0);
	    q.push(src);
	    vis[x1][y1]=1;
	    int shortest=INT_MAX;
	    while(!q.empty()) {
	        Cell cell = q.front();
	        q.pop();
	        int x = cell.x;
	        int y = cell.y;
	        int dist = cell.dist;

	        //cout << "x: "<<x<<", y: "<<y<<endl;

	        if(x==x2 && y==y2) {
	            shortest=min(shortest, dist);
	            //cout << dist << endl;
	            break;
	        }

	        //int neighbors[2][8]={2, 1, -1, -2, -2, -1, 1, 2, 1, 2, 2, 1, -1, -2, -2, -1};
	        int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
            int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

	        for(int j=0; j<8; j++) {
	            //int xd=neighbors[0][j];
	            //int yd=neighbors[1][j];
	            int xd=dx[j];
	            int yd=dy[j];
	            if(x+xd>0 && x+xd<=m && y+yd>0 && y+yd<=n && !vis[x+xd][y+yd]) {

	                Cell cell(x+xd, y+yd, dist+1);
	                q.push(cell);
	                vis[x+xd][y+yd]=1;
	            }
	        }
	    }
	    cout << (shortest==INT_MAX ? -1 : shortest) << endl;
	}
	return 0;
}

/****
Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Constraints:
1<=T<=100
1<=N<=20
1<=knight_pos,targer_pos<=N

Example:
Input:
2
6
4 5
1 1
20
5 7
15 20

Output:
3
9

Explanation:
Testcase 1:
The most optimal path is: (4,5) -> (2,4) -> (3,2) -> (1,1). 
Hence, we can reach the destination in 3 steps.

Solution:
Similar to knight-walk
  ****/


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int knightTour(vector<vector<int>> a, int n, int x1, int y1, int x2, int y2, int cnt)
{
    int ret=-1;
    //cout << "x1: "<<x1<<", y1: "<<y1<<", x2: "<<x2<<", y2: "<<y2 << endl;

    if(x1<0 || y1<0 || x1>=n || y1>=n || a[x1][y1])
        return -1;

    if(x1==x2 && y1==y2)
        return cnt;

    a[x1][y1]=1;

    ret = knightTour(a, n, x1+2, y1-1, x2, y2, cnt+1);
    if(ret>=0) return ret;

    ret = knightTour(a, n, x1+2, y1+1, x2, y2, cnt+1);
    if(ret>=0) return ret;

    ret = knightTour(a, n, x1+1, y1-2, x2, y2, cnt+1);
    if(ret>=0) return ret;

    ret = knightTour(a, n, x1+1, y1+2, x2, y2, cnt+1);
    if(ret>=0) return ret;

    ret = knightTour(a, n, x1-2, y1-1, x2, y2, cnt+1);
    if(ret>=0) return ret;

    ret = knightTour(a, n, x1-2, y1+1, x2, y2, cnt+1);
    if(ret>=0) return ret;
    ret = knightTour(a, n, x1-1, y1-2, x2, y2, cnt+1);
    if(ret>=0) return ret;
    ret = knightTour(a, n, x1-1, y1+2, x2, y2, cnt+1);

    return ret;
}

struct Cell
{
    int x, y, dist;
    Cell(int x1, int y1, int d) : x(x1), y(y1), dist(d)
    {}
};

int bfs(int n, int x1, int y1, int x2, int y2)
{
    int vis[n+1][n+1] = {0};
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
            if(x+xd>0 && x+xd<=n && y+yd>0 && y+yd<=n && !vis[x+xd][y+yd]) {

                Cell cell(x+xd, y+yd, dist+1);
                q.push(cell);
                vis[x+xd][y+yd]=1;
            }
        }
    }
    return (shortest==INT_MAX ? -1 : shortest);
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;

	    int x1, y1, x2, y2;
	    cin >> x1 >> y1 >> x2 >> y2;

	    cout << bfs(n, x1, y1, x2, y2) << endl;
	    //--x1; --y1; --x2; --y2;
	}
	return 0;
}

/****
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the square chessboard. The next line contains the X-Y coordinates of the knight. The next line contains the X-Y coordinates of the target. 

Output:
Print the minimum steps the Knight will take to reach the target position.

Your Task:
You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (knightPos), the target position of Knight (targetPos) and the size of the chess board (N) as inputs and returns the minimum number of steps required by the knight to reach from its current position to the given target position.

Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(N2).

Constraints:
1 <= T <= 100
1 <= N <= 1000
1 <= knight_pos(X, Y), targer_pos(X, Y) <= N

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
Test Case 1:

Knight takes 3 step to reach from (4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.
  ****/

// User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
int minStepToReachTarget(int knightPos[], int targetPos[], int N)
{
    // code here
    struct Move
    {
        int dist, x, y;
        Move(int i, int j, int k)
        { x=i; y=j; dist=k; }
    };
    bool vis[N][N];
    memset(vis, false, N*N);

    int dx[] ={-1, 1, 2, 2, 1, -1, -2, -2};
    int dy[] ={2, 2, 1, -1, -2, -2, -1, 1};

    int x1=knightPos[0]-1;
    int y1=knightPos[1]-1;
    int x2=targetPos[0]-1;
    int y2=targetPos[1]-1;

    queue<Move> que;
    Move move(x1, y1, 0);
    vis[x1][y1] = true;
    que.push(move);

    while(!que.empty())
    {

        Move move = que.front();
        que.pop();

        int i=move.x;
        int j=move.y;
        int d=move.dist;

        if(i==x2 && j==y2)
            return d;


        for(int k=0; k<8; k++) {
            if(i+dx[k]>=0 && i+dx[k]<N && j+dy[k]>=0 && j+dy[k]<N && !vis[i+dx[k]][j+dy[k]]) {

                if(i+dx[k]==x2 && j+dy[k]==y2)
                    return d+1;

                Move move(i+dx[k], j+dy[k], d+1);

                que.push(move);
                vis[i+dx[k]][j+dy[k]]=true;
            }
        }

    }
}

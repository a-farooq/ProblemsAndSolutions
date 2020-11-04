/****
Given a matrix of dimension RxC where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains two integers R and C, where R is the number of rows and C is the number of columns in the matrix[][]. Next line contains space separated RxC elements.

Output:
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

User Task:
Complete the function rotOranges which takes the RxC matrix, R and C as input and returns the minimum time required to rot all oranges.

Constraints:
1 <= T <= 100
1 <= R <= 1000
1 <= C <= 1000
0 <= matrix[i][j] <= 2

Expected Time Complexity : O(r*c)

Example:
Input:
2
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
3 5
2 1 0 2 1 0 0 1 2 1 1 0 0 2 1

Output:
2
-1

Explanation:
Testcase 1:
2 | 1 | 0 | 2 | 1
1 | 0 | 1 | 2 | 1
1 | 0 | 0 | 2 | 1

Oranges at positions {0,0}, {0, 3}, {1, 3} and {2, 3} will rot oranges at {0, 1}, {1, 0}, {0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st unit time. And, during 2nd unit time, orange at {1, 0} got rotten and will rot orange at {2, 0}. Hence, total 2 unit of time is required to rot all oranges.
  ****/

//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    // Your code goes here
    queue<int> q;

    int fresh=0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(matrix[i][j]==1)
                fresh++;
            else if(matrix[i][j]==2) {
                q.push(i*C+j);
            }
        }
    }

    int timer=0;

    while(!q.empty()) {
        int size = q.size();
        //cout << "size: "<<size << endl;

        while(size>0) {
            int cell = q.front();
            q.pop();
            int i=cell/C;
            int j=cell%C;
            //cout << cell << ", "<<i <<", "<< j << endl;

            if((j+1)<C && matrix[i][j+1]==1) {
                matrix[i][j+1]=2;
                q.push(i*C+j+1);
                fresh--;
            }

            if(i+1<R && matrix[i+1][j]==1) {
                matrix[i+1][j]=2;
                q.push((i+1)*C+j);
                fresh--;
            }
            if(j-1>=0 && matrix[i][j-1]==1) {
                matrix[i][j-1]=2;
                q.push(i*C+j-1);
                fresh--;
            }
            if(i-1>=0 && matrix[i-1][j]==1) {
                matrix[i-1][j]=2;
                q.push((i-1)*C+j);
                fresh--;
            }

            size--;
        }

        if(q.empty()) break;

        timer++;
    }

    return fresh==0?timer:-1;
}

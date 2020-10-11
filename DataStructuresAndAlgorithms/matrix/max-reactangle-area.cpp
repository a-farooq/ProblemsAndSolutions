/****
Given a binary matrix. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Example 1:

Input:
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output: 8
Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
Your Task: 
Your task is to complete the function maxArea which returns the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two integers n and m which denotes the size of the matrix M. 

Expected Time Complexity : O(n*m)
Expected Auixiliary Space : O(m)

Constraints:
1<=n,m<=1000
0<=M[][]<=1

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Algorithm:
Call histogram area program for each row (modified with upper row sum)
  ****/

int maxHistogramArea(int*hist, int n)
{
    int max_area = 0;
    stack<int> stk;
    int i=0;
    while(i < n)
    {
        if(stk.empty() || hist[i]>=hist[stk.top()])
            stk.push(i++);
        else {
            int top = stk.top();
            stk.pop();
            int area_with_top = hist[top]*(stk.empty()?i:i-stk.top()-1);
            max_area = max(max_area, area_with_top);
        }
    }
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        int area_with_top = hist[top]*(stk.empty()?i:i-stk.top()-1);
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m)
{
    // Your code here
    int max_area = maxHistogramArea(M[0], m);

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(M[i][j])
                M[i][j] += M[i-1][j];
        }
        int row_area = maxHistogramArea(M[i], m);
        max_area = max(max_area, row_area);
    }
    return max_area;
}

/****
Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(1)

Constraints:
2 <= R, C <= 100
0 <= matrixi <= 100
  ****/

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
    {
        // code here
        vector<int> res;
        int top=0, bot=r-1, lt=0, rt=c-1;

        while(1)
        {
            if(lt>rt) break;
            for(int j=lt; j<=rt; j++)
                res.push_back(matrix[top][j]);
            top++;

            if(top>bot) break;
            for(int i=top; i<=bot; i++)
                res.push_back(matrix[i][rt]);
            rt--;

            if(rt<lt) break;
            for(int j=rt; j>=lt; j--)
                res.push_back(matrix[bot][j]);
            bot--;

            if(bot<top) break;
            for(int i=bot; i>=top; i--)
                res.push_back(matrix[i][lt]);
            lt++;
        }

        return res;
    }
};

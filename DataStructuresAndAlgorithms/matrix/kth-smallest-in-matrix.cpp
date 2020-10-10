/****
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N

Algorithm:
Similar to merge k sorted arrays using heap
  ****/

struct HeapNode
{
    int val, row, col;
    HeapNode(int a, int b, int c) : val(a), row(b), col(c)
    {}
};

struct cmp
{
    int operator()(HeapNode& s1, HeapNode& s2)
    {
        return s1.val > s2.val;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int ptr=0;
    priority_queue<HeapNode, vector<HeapNode>, cmp> pqmin;

    //push first element of each row into minheap
    for(int i=0; i<n; i++) {
        HeapNode node(mat[i][0], i, 0);
        pqmin.push(node);
    }

    //add the top of heap to out array and insert next (of same array as top)
    //into heap
    while(!pqmin.empty()) {
        HeapNode node_min = pqmin.top();
        pqmin.pop();

        if(--k==0) return node_min.val;

        int row = node_min.row;
        int col = node_min.col;
        if(col < n-1) {
            HeapNode node(mat[row][col+1], row, col+1);
            pqmin.push(node);
        }
    }

}

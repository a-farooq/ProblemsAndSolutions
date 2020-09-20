/****
Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.


Example 1:

Input :      
           3                               
         /    \                          
       4       5                     
      /  \      
    -10   4                          

Output: 16

Explanation :
Maximum Sum lies between leaf node 4 and 5.
4 + 4 + 3 + 5 = 16.

Example 2:

Input :    
            -15                               
         /      \                          
        5         6                      
      /  \       / \
    -8    1     3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  

Output :  27

Explanation:
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

Your Task:  
You dont need to read input or print anything. Complete the function maxPathSum() which takes root node as input parameter and returns the maximum sum between 2 leaf nodes.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of Tree)


Constraints:
1 ≤ N ≤ 10^4

Solution:
One can find the maximum sum using single traversal of binary tree, the idea is to maintain two values in recursive calls
1) Maximum root to leaf path sum for the subtree rooted under current node.
2) The maximum path sum between leaves (desired output).

For every visited node X, find the maximum root to leaf sum in left and right subtrees of X.
Add the two values with X->data, and compare the sum with maximum path sum found so far.
  ****/

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int maxPathSumUtil(Node* root, int& res)
{
    if(!root) return 0;
    if(!root->left && !root->right)
        return root->data;

    int lv = maxPathSumUtil(root->left, res);
    int rv = maxPathSumUtil(root->right, res);

    //update max only if both child are present
    if(root->left && root->right) {
        res = max(res, lv+rv+root->data);
        return max(lv, rv)+root->data;
    }
    /*
    else if(root->left)
        res = max(res, lv);
    else if(root->right)
        res = max(res, rv);
    */
    //if left is null, lv=0; if right is null, rv=0
    //taking max here will suppress negative value due to 0 of null child
    return lv+rv+root->data;
}
int maxPathSum(Node* root)
{
    int res=INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}

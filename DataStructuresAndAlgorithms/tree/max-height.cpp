/****
Given a binary tree, find its minimum depth.

Example 1:

Input:
            1
          /   \
         3     2
        /
       4           

Output: 2

Explanation:
Minimum depth is between nodes 1 and 3.
Example 2:

Input:
             10
          /     \
        20       30
          \        \   
          40        60 
                   /
                  2 

Output: 3

Explanation:
Minimum depth is between nodes 10,20 and 40.

Your Task:  
You dont need to read input or print anything. Complete the function minDepth() which takes root node as input parameter and returns the minimum depth.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^5
  ****/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

int maxDepthUtil(Node* root)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return 1;

    int ld = maxDepthUtil(root->left);
    int rd = maxDepthUtil(root->right);

    return 1+max(ld, rd);
}

/*You are required to complete this method*/
int maxDepth(Node *node)
{
    return maxDepthUtil(node);
}

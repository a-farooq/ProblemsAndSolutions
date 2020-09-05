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

void minDepthUtil2(Node* root, int h, int& mini)
{
    if(!root) {
        return;
    }

    if(!root->left && !root->right) {
        mini = min(mini, h);
    }

    minDepthUtil2(root->left, h+1, mini);
    minDepthUtil2(root->right, h+1, mini);
}

int minDepthUtil(Node* root)
{
    if(!root)
        return INT_MAX;

    if(!root->left && !root->right)
        return 1;

    int ld = minDepthUtil(root->left);
    int rd = minDepthUtil(root->right);

    return 1+min(ld, rd);
}

/*You are required to complete this method*/
int minDepth(Node *node)
{
    int mini = INT_MAX;
    //minDepthUtil2(node, 1, mini);
    mini = minDepthUtil(node);
    return mini;
}

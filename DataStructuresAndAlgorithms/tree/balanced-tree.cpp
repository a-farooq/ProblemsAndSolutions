/****
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 
Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= Number of nodes <= 10ˆ5
0 <= Data of a node <= 10ˆ6

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree


  ****/

/* A binary tree node structure

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

int height(Node* root, bool & bal)
{
    if(!bal) return 0;
    if(!root) return 0;

    int lh = height(root->left, bal);
    int rh = height(root->right, bal);

    if(abs(lh-rh)>1) bal = false;

    return max(lh, rh) + 1;
}
// This function should return tree if passed  tree
// is balanced, else false.
bool isBalanced(Node *root)
{
    bool bal = true;
    height(root, bal);

    return bal;
}


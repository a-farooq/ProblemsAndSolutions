/****
Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^3
  ****/

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

bool checkUtil(Node* root, int level, int& leafLevel)
{
    if(!root) return true;

    if(!root->left && !root->right) {
        if(leafLevel>=0) {
            if(level!= leafLevel)
                return false;
        }
        else leafLevel = level;
    }

    bool ret = checkUtil(root->left, level+1, leafLevel);
    if(!ret) return ret;
    ret = checkUtil(root->right, level+1, leafLevel);
    return ret;
}

/*You are required to complete this method*/
bool check(Node *root)
{
    int leafLevel = -1;
    return checkUtil(root, 0, leafLevel);
}

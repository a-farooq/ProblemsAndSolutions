/****
Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Example 1:

Input:
       1
     /   \
    2     3
Output: 2

Example 2:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output: 13
Explanation:
sum = 6 + 7 = 13
Your Task:
You don't need to read input or print anything. Your task is to complete the function leftLeavesSum() which takes the root node of the tree as input and returns the sum of all the left leaf nodes present in the given binary tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1<=Number of nodes<=10^5


  ****/

/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
int leftLeavesSumUtil(Node* root, short dir)
{
    if(!root) return 0;

    if(!dir) {
        if(!root->left && !root->right)
            return root->data;
    }

    int lsum = leftLeavesSumUtil(root->left, 0);
    int rsum = leftLeavesSumUtil(root->right, 1);

    return lsum+rsum;
}
// function should return the sum of all
// left leaf nodes
int leftLeavesSum(Node *root)
{
    if(!root) return 0;

    return leftLeavesSumUtil(root->left, 0) + leftLeavesSumUtil(root->right, 1);
}

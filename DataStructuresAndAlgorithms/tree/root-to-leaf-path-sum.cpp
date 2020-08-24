/****
Given a binary tree and an integer S, check whether there is root to leaf path wiht its sum as S.

Example 1:

Input:
Tree = 
            1
          /   \
        2      3
S = 2

Output: 0

Explanation:
There is no root to leaf path with sum 2.
Example 2:

Input:
Tree = 
            1
          /   \
        2      3
S = 4

Output: 1

Explanation:
The sum of path from leaf node 3 to root 1 is 4.

Your Task:  
You dont need to read input or print anything. Complete the function hasPathSum() which takes root node and target sum S as input parameter and returns true if path exists otherwise it returns false.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ N ≤ 10^4
1 ≤ S ≤ 10^6
  ****/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool pathSum(Node *root, int sum, int cursum)
{
    if(!root) return false;

    if(!root->left && !root->right) //root is leaf node
    {
        if(cursum+root->data == sum)
            return true;
        return false;
    }
    if(pathSum(root->left, sum, cursum+root->data)) return true;
    if(pathSum(root->right, sum, cursum+root->data)) return true;

    return false;
}
/*you are required to
complete this function */
bool hasPathSum(Node *root, int sum) {

    //return pathSum(root, sum, 0);

    if(!root) return false;

    if(!root->left && !root->right) //root is leaf node
    {
        if(0 == sum-root->data) return true;
        return false;
    }

    if(hasPathSum(root->left, sum-root->data)) return true;
    if(hasPathSum(root->right, sum-root->data)) return true;

    return false;
}

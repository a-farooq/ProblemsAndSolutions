/****
Given a Binary Tree, you need to find the maximum value which you can get by subtracting the value of node B from the value of node A, where A and B are two nodes of the binary tree and A is an ancestor of B. 

Example 1:

Input:
    5
 /    \
2      1
Output: 4
Explanation:The maximum difference we can
get is 4, which is bewteen 5 and 1.
Example 2:

Input:
      1
    /    \
   2      3
           \
            7
Output: -1
Explanation:The maximum difference we can
get is -1, which is between 1 and 2.
Your Task:
The task is to complete the function maxDiff() which finds the maximum difference between the node and its ancestor.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= Number of edges <= 10^4
0 <= Data of a node <= 10^5


  ****/

/* A binary tree node

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

int maxDiffUtil(Node* root, int&maxDiff)
{
    if(!root) return INT_MAX;

    if(!root->left && !root->right)
        return root->data;

    int ld = maxDiffUtil(root->left, maxDiff);
    int rd = maxDiffUtil(root->right, maxDiff);

    //ancestors level is not given as immediate
    int mini = min(ld, rd);

    maxDiff=max(maxDiff, root->data-mini);

    return min(mini, root->data);

}
/* Your are required to
complete this method*/
int maxDiff(Node* root)
{
    int maxi = INT_MIN;
    maxDiffUtil(root, maxi);
    return maxi;
}

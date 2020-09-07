/****
Given a BST and an integer K. Find the Kth Smallest element in the BST. 

Example 1:

Input:
      2
    /   \
   1     3
K = 2
Output: 2
Example 2:

Input:
        2
      /  \
     1    3
K = 5
Output: -1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function KthSmallestElement() which takes the root of the BST and integer K as inputs and return the Kth smallest element in the BST, if no such element exists return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1<=Number of nodes<=100000

Solution:
Similar to kth largest BST node problem
  ****/

/*Complete the function below

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

int KthSmallest(Node* root, int& k)
{
    int ret = 0;
    if(!root) return ret;

    ret = KthSmallest(root->left, k);
    if(!k) return ret;

    if(--k == 0)
        return root->data;

    ret = KthSmallest(root->right, k);
    if(!k) return ret;

    return ret;
}
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{
    int ret = KthSmallest(root, K);
    if(!K) return ret;
    else return -1;
}

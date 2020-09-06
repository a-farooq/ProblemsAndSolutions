/****
Given A binary Tree. Your task is to remove all the half nodes (which has only one child).

Example 1:

Input:
         7
       /   \
      7     8
     / 
    2
Output: 2 7 8 
Example 2:

Input:
         2
       /   \
      7     5
       \      \
        9      1
       /  \
      11   4
Output: 1 6 11 2 4
Your Task:
You don't need to read input or print anything. Your task is to complete the function removeHalfNodes() which takes the root node of the tree as input and returns the root node of the modified tree after removing all the half nodes, ie the ones having just a single child node. (The inorder traversal of the returned tree is printed by the driver's code.)
For example consider the below tree.


Nodes 7, 5 and 9 are half nodes as one of their child is Null. We need to remove all such half nodes and return the root pointer of following new tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Binary Tree).

Constraints:
1<=Number of nodes<=10^4

Solution:
The idea is to use post-order traversal to solve this problem efficiently. We first process the left children, then right children, and finally the node itself. So we form the new tree bottom up, starting from the leaves towards the root. By the time we process the current node, both its left and right subtrees were already processed.
  ****/

/*Complete the function below
Node is as follows:
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

// Return the root of the modified tree after removing all the half nodes.
Node *RemoveHalfNodes(Node *root)
{
    if(!root) return nullptr;

    root->left = RemoveHalfNodes(root->left);

    root->right = RemoveHalfNodes(root->right);

    if(!root->left && root->right) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->left && !root->right) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    return root;
}

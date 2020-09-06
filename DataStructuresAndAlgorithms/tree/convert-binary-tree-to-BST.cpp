/****
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.


Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).


Constraints:
1 <= Number of nodes <= 1000

Solution:
The inorder traversal of a BST generates the node values in a sorted order.
Take the data of binary in an array or vector
sort the vector. This is inorder traversal of a BST.
Traverse original binary tree in inorder along with the vector.
Fill the data of binary tree with that of vector. This creates BST.
  ****/

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void inorder_binary(Node* root, vector<int>& in)
{
    if(!root) return;

    inorder_binary(root->left, in);
    //cout << root->data << " ";
    in.push_back(root->data);
    inorder_binary(root->right, in);
}

void createBST(Node* root, const vector<int> in, int& idx)
{
    if(!root) return;

    createBST(root->left, in, idx);
    root->data = in[idx++];
    createBST(root->right, in, idx);
}

// The given root is the root of the Binary Tree
// Return the root of the generated BST
Node *binaryTreeToBST (Node *root)
{
    vector<int> in;
    int idx = 0;
    inorder_binary(root, in);
    //cout << endl;
    sort(in.begin(), in.end());
    createBST(root, in, idx);
    //inorder_binary(root, in);
    //cout << endl;
    return root;
}

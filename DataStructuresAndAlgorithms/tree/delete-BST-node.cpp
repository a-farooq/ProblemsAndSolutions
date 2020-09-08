/****
Given a Binary Search Tree and a node value X. Delete the node with the given value X from the BST. If no node with value x exists, then do not make any change. 

Example 1:

Input:
      2
    /   \
   1     3
X = 12
Output: 1 2 3
Explanation: In the given input there
is no node with value 12 , so the tree
will remain same.
Example 2:

Input:
            1
             \
              2
                \
                 8 
               /    \
              5      11
            /  \    /  \
           4    7  9   12
X = 9
Output: 1 2 4 5 7 8 11 12
Explanation: In the given input tree after
deleting 9 will be
             1
              \
               2
                 \
                  8
                 /   \
                5     11
               /  \     \
              4    7     12
Your Task:
You don't need to read input or print anything. Your task is to complete the function deleteNode() which takes two arguments. The first being the root of the tree, and an integer 'X' denoting the node value to be deleted from the BST. Return the root of the BST after deleting the node with value X. Do not make any update if there's no node with value X present in the BST.

Note: The generated output will be the inorder traversal of the modified tree.
 

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).
 

Constraints:
1 <= N <= 10^5
  ****/

/* The structure of a BST Node is as follows:

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

Node* find_min(Node* root)
{
    if(!root) return nullptr;

    Node* node = root;
    while(node->left) {
        node = node->left;
    }
    return node;
}

// Return the root of the modified BST after deleting the node with value X
Node *deleteNode(Node *root,  int X)
{
    if(!root) return nullptr;

    if(root->data > X) {
        root->left = deleteNode(root->left, X);
    }
    else if(root->data < X) {
        root->right = deleteNode(root->right, X);
    }
    else {
        if(!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if(!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        else {
            //find minimum (inorder successor) in right subtree)
            Node* in_succ = find_min(root->right);
            root->data = in_succ->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}


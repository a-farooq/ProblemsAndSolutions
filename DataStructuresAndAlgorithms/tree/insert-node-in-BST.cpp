/****
Given a BST and a key K. Insert a new Node with value equal to K into the BST. 

Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
Note: The generated output contains the inorder traversal of the modified tree.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).


Constraints:
1 <= Number of nodes <= 10^5
1 <= K <= 10^6
  ****/

/* The structure of a BST node is as follows:

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

// The function returns the root of the BST (currently rooted at 'root')
// after inserting a new Node with value 'Key' into it.
Node* insert(Node* root, int key)
{
    if(!root) {
        Node *newnode = new Node(key);
        return newnode;
    }

    Node* node = nullptr;

    if(key < root->data) root->left = insert(root->left, key);

    else if(key > root->data) root->right = insert(root->right, key);

    return root;
    /*
    if(key < root->data) {
        Node *newnode = new Node(key);
        root->left = newnode;
    }
    else {
        Node *newnode = new Node(key);
        root->right = newnode;
    }*/
}

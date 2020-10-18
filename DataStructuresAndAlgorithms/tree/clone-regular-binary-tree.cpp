/****
Given a binary tree with the usual left and right pointers. Clone the given tree.

Example 1:

Input:

Output: 1
Explanation: The tree was cloned successfully.

Your Task:
No need to read input or print anything. Complete the function cloneTree() which takes root of the given tree as input parameter and returns the root of the cloned tree. 

Note: The output is 1 if the tree is cloned successfully. Otherwise output is 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000
  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

/* The function should clone the passed tree and return
   root of the cloned tree */
Node* cloneTree(Node* r1)
{
   //Your code here
	//cloning a regular binary tree
    if(!r1)
        return nullptr;

    Node* root = new Node(r1->data);

    if(!r1->left && !r1->right) {
        return root;
    }

    root->left = cloneTree(r1->left);
    root->right = cloneTree(r1->right);

    return root;
}


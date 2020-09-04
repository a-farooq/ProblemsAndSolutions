/****
Given a binary tree. Check whether it is a BST or not.

Example 1:

Input:
    2
 /    \
1      3
Output: 1
Example 2:

Input:
  2
   \
    7
     \
      6
       \
        5
         \
          9
           \
            2
             \
              6
Output: 0
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBST() which takes the root of the tree as a parameter and returns true if the given binary tree is BST, else returns false. The printing is done by the driver's code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
0 <= Number of edges <= 100000

Solution:

The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.

// * Returns true if the given tree is a binary search tree
 (efficient version). * /
int isBST(struct node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/ * Returns true if the given tree is a BST and its
 values are >= min and <= max. * /
int isBSTUtil(struct node* node, int min, int max)
The time complexity for this will be O(N) as we need to check it for all the nodes whether they lie in the correct range or not.
Whereas, the auxiliary space we used for recursion in O(height) as we make the right subtree call only when the left subtree has been checked.
  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
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

bool BSTUtil(Node* root, int lb, int ub)
{
    if(!root) return true;

    if(root->data >= ub || root->data < lb)
        return false;

    bool ret = BSTUtil(root->left, lb, root->data);
    if(!ret) return false;

    ret = BSTUtil(root->right, root->data, ub);

    return ret;
}
// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    // Your code here
    if(!root) return false;

    return BSTUtil(root, INT_MIN, INT_MAX);
}


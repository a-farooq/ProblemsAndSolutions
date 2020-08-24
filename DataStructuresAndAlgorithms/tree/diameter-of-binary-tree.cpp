/****
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).



Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes node as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
  ****/

/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int height(Node* root)
{
    if(!root) return 0;
    return max(height(root->left), height(root->right))+1;
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    // Your code here
    if(!node) return 0;

    if(!node->left && !node->right) return 1;

    int lh = height(node->left);
    int rh = height(node->right);
    int dia = lh+rh+1;

    int ld = diameter(node->left);//height(node->left->left) + height(node->left->right)+1;
    int rd = diameter(node->right);//height(node->right->left) + height(node->right->right)+1;

    return max(max(ld, rd), dia);
    //return max(lh, rh) + 1;
    //diameter = height(node->left) + height(node->right) + 1;

    //return diameter(node->left) + diameter(node->right) + 1;
}

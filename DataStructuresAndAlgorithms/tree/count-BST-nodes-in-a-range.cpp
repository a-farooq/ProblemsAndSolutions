/****
Given a Binary Search Tree (BST) and a range l-h(inclusive), count the number of nodes in the BST that lie in the given range.

The values smaller than root go to the left side
The values greater and equal to the root go to the right side
Example 1:

Input:
      10
     /  \
    5    50
   /    /  \
  1    40  100
l = 5, h = 45
Output: 3
Explanation: 5 10 40 are the node in the
range
Example 2:

Input:
     5
    /  \
   4    6
  /      \
 3        7
l = 2, h = 8
Output: 5
Explanation: All the nodes are in the
given range.
Your Task:
This is a function problem. You don't have to take input. You are required to complete the function getCountOfNode() that takes root, l ,h as parameters and returns the count.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 100
1 <= l < h < 10^3
  ****/

/*

The structure of a BST node is as follows:

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
int getCountOfNode(Node *root, int l, int h)
{
    if(!root) return 0;
    /*
    //visits every node (subtree) of tree
    int count=0;

    // check if data of root lies in range of l and r
    if(root->data>=l && root->data<=h)
        count++;

    // recurse for left and right
    return count+getCountOfNode(root->left, l, h)+getCountOfNode(root->right, l, h);
    */
    //visits nodes (subtrees) selectively
    int lc = 0, rc = 0, cc = 0;

    if(l <= root->data && root->data <= h)
    {
        cc = 1;
        lc = getCountOfNode(root->left, l, h);
        rc = getCountOfNode(root->right, l, h);
    }
    else if(root->data >= h) {
        lc = getCountOfNode(root->left, l, h);
    }
    else if(root->data <= l) {
        rc = getCountOfNode(root->right, l, h);
    }

    return cc+lc+rc;
}

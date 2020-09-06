/****
Given a special Binary Tree whose leaf nodes are connected to form a circular doubly linked list. Find the height of this special Binary Tree.

Example 1:

Input:
        1
      /   \
     2     3
    /
   4
Output: 3
​Explanation: There are 3 edges and 4
nodes in spiral tree where leaf nodes
4 and 3 are connected in circular
doubly linked list form. Thus the
height of spiral tree is 3.
Example 2:

Input:
        1
      /   \
     2     3
    / \
   4   5
  /
 6
Output: 4
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTreeHeight() which takes the root of the special Binary Tree as its input and returns the Height of this special Binary Tree.
In a special Binary Tree, the leaf nodes form a circular doubly linked list.
For Example:

      1
     /   \ 
    2    3
   /  \
  4  5
 /  
6 

In the above binary tree, 6, 5 and 3 are leaf nodes and they form a circular doubly linked list. Here, the left pointer of leaf node will act as a previous pointer of circular doubly linked list and its right pointer will act as next pointer of circular doubly linked list.

Expected Time Complexity: O(Height of the Tree).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^4
  ****/

/*Structure of the node of the binary tree

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
// Return the height of the given special binary tree
int findTreeHeight(Node* root)
{
    if(!root) return 0;

    if(root->right && root->right->left==root)
        return 1;
    //if(root->left && root->left->right==root)
    //    return 1;

    int lh = findTreeHeight(root->left);
    int rh = findTreeHeight(root->right);

    return 1+max(lh, rh);
}

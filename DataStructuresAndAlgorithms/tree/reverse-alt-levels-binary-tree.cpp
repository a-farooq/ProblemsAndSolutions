/****
Given a complete binary tree, reverse the nodes present at alternate levels.

Example 1:

Input:
             1
          /   \
        3      2

Output:

             1
          /   \
        2      3

Explanation: Nodes at level 2 are reversed.
Example 2:

Input:
              1
          /      \
         2        3
       /  \      /  \
     42   51   63   72

Output:
             1
          /      \
         3        2
       /  \      /  \
     42   51   63   72

Explanation:
Nodes at level 2 are reversed.
Level 1 and 3 remain as it is.

Your Task:  
You dont need to read input or print anything. Complete the function reverseAlternate() which takes root node as input parameter and modifies the given tree in-place.

Note: If you click on Compile and Test the output will be the in-order traversal of the modified tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^4

Solution:

  ****/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void reverseNodes(Node* root1, Node* root2, int level)
{
    if(!root1 || !root2) return;

    if(level%2==0) {
        swap(root1->data, root2->data);
    }

    reverseNodes(root1->left, root2->right, level+1);
    reverseNodes(root1->right, root2->left, level+1);
}

void reverseAlternate(Node *root)
{
    reverseNodes(root->left, root->right, 0);
}


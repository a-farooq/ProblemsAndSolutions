/****
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2
Example 2:

Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
Your Task:
Just complete the function rightView() that takes node as parameter and prints the right view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5.

  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
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

//only one node at a level must be visible from right side
//keep track of max level
void rightViewUtil(Node* root, int level, int& maxlevel)
{
    if(!root) return;

    if(level > maxlevel) {
        cout << root->data << " ";
        maxlevel = level;
    }

    rightViewUtil(root->right, level+1, maxlevel);

    rightViewUtil(root->left, level+1, maxlevel);
}


// Should print right view of tree
void rightView(Node *root)
{
    int maxi = -1;
    rightViewUtil(root, 0, maxi);
}

/****
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
  ****/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

void leftViewUtil(Node* root, int level, int& maxlevel)
{
    if(!root) return;

    if(level > maxlevel) {
        cout << root->data << " ";
        maxlevel = level;
    }

    leftViewUtil(root->left, level+1, maxlevel);

    leftViewUtil(root->right, level+1, maxlevel);
}

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
    int maxi = -1;
    leftViewUtil(root, 0, maxi);
}

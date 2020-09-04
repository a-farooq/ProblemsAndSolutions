/****
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.
For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
          1
       /    \
     2       3
   /  \    /   \
  4    5  6    7
   \
     8
Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
             2
         /      \
       9        5
     /   \
    4      3
 

Your Task:
Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as inputs and returns the root node of the newly constructed Binary Tree. The pre order traversal of the returned node is printed by the driver's code.

Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^3
1 <= in[i], post[i] <= 10^3

Complete Solution:

Maintain a global variable postindex, initailly pointing to n-1
For every functional call of buildtree function, make a newnode to store the value at post[postindex]
Decreement postindex by 1
search for this element in inorder arary, and store the index
call this buildtree function, first for right subtree with index+1 and end, and then for left subtree with start and index -1
return the newnode
  ****/

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int findroot(int a[], int start, int end, int x)
{
    for(int i=start; i <= end; i++)
        if(a[i]==x) return i;
}

Node* buildUtil(int in[], int post[], int start, int end, int& postIndex)
{
    if(start > end) return nullptr;

    Node* node = new Node(post[postIndex--]);

    if(start == end) return node;

    int rootInIdx = findroot(in, start, end, node->data);

    node->right = buildUtil(in, post, rootInIdx+1, end, postIndex);

    node->left = buildUtil(in, post, start, rootInIdx-1, postIndex);

    return node;
}

// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node *buildTree(int in[], int post[], int n)
{
    int postIndex=n-1;
    return buildUtil(in, post, 0, n-1, postIndex);
}

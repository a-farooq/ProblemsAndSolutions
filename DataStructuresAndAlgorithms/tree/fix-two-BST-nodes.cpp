/****
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.

Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.

Example 1:

Input:
       10
     /    \
    5      8
   / \
  2   20
Output: 1
Explanation:
 
Example 2:

Input:
         11
       /    \
      3      17
       \    /
        4  10
Output: 1
Your Task:
You don't need to take any input. Just complete the function correctBst() that takes root node as parameter. The function should return the root of corrected BST. BST will then be checked by driver code and 0 or 1 will be printed.

Expected Time Complexity : O(n)

Expected Auxiliary Space : O(1)

Constraints:
1 <= Number of nodes <= 1000


  ****/

/*Complete the function
Node is as follows:

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

*/

void correctBSTUtil(Node* root, Node** first, Node** mid, Node** last, Node** prev)
{
    if(!root) return;

    correctBSTUtil(root->left, first, mid, last, prev);

    if(*prev && (*prev)->data > root->data) {
        if(!*first) {
            *first = *prev;
            *mid = root;
        }
        else {
            *last = root;
        }
    }

    *prev = root;
    correctBSTUtil(root->right, first, mid, last, prev);
}
struct Node *correctBST( struct Node* root )
{
    // add code here.
    Node* first, *mid, *last, *prev;
    first = mid = last = prev = nullptr;

    correctBSTUtil(root, &first, &mid, &last, &prev);
    if(first && last) {
        //swap( &last->data, &first->data );
        int tmp = first->data;
        first->data = last->data;
        last->data = tmp;

    }
    else if(first && mid) {
        //swap(&(first->data), &(mid->data));
        int tmp = first->data;
        first->data = mid->data;
        mid->data = tmp;
    }

    return root;
}

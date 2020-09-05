/****
Given a Binary Search Tree and a range. Find all the numbers in the BST that lie in the given range.
Note: Element greater than or equal to root go to the right side.

 

Example 1:

Input:
       17
     /    \
    4     18
  /   \
 2     9 
l = 4, h = 24
Output: 4 9 17 18 

Example 2:

Input:
       16
     /    \
    7     20
  /   \
 1    10
l = 13, h = 23
Output: 16 20 

Your Task:
You don't need to read input or print anything. Your task is to complete the function printNearNodes() which takes the root Node of the BST and the range elements low and high as inputs and returns an array that contains the BST elements in the given range low to high (inclusive) in non-decreasing order.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes <= 10^4
1 <= l < h < 10^5
  ****/

/* The structure of a BST Node is as follows:

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

void getRangeNode(Node *root, int l, int h, vector<int>& out)
{
    if(!root) return;

    //visits nodes (subtrees) selectively
    if(l <= root->data && root->data <= h)
    {
        out.push_back(root->data);
        getRangeNode(root->left, l, h, out);
        getRangeNode(root->right, l, h, out);
    }
    else if(root->data >= h) {
        //whole range is less than BST subtree root, move to left
        getRangeNode(root->left, l, h, out);
    }
    else if(root->data <= l) {
        //whole range is more than BST subtree root, move to right
        getRangeNode(root->right, l, h, out);
    }
}

// returns an array of node values in the BST (rooted at 'root')
// that lie in the given range [low, high]
vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> vec;
    getRangeNode(root, low, high, vec);
    sort(vec.begin(), vec.end());
    return vec;
}


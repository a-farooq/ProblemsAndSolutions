/****
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
Your Task:
You don't have to read any input. Just complete the function getMaxWidth() that takes node as parameter and returns the maximum width. The printing is done by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= edges <= 1000
1 <= nodes values <= 10^5

  ****/

/*  Structure of a Binary Tree

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


void getWidthAtAllLevels(Node* root, unordered_map<int,int>& um, int level)
{
    if(!root) return;

    um[level]++;
    um[0] = max(um[0], um[level]);

    getWidthAtAllLevels(root->left, um, level+1);
    getWidthAtAllLevels(root->right, um, level+1);
}

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(!root) return 0;

    unordered_map<int,int> um;
    getWidthAtAllLevels(root, um, 1);
    return um[0];
}

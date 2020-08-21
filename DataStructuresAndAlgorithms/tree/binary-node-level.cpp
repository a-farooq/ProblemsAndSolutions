/****
Given a Binary Tree and a target key you need to find the level of target key in the given Binary Tree.

           3
         /   \
        2     5
      /   \
     1     4
Key: 4
Level: 3  
Note: if no such key exists then return 0.

Example 1:

Input:
        1
      /   \
     2     3
target = 4
Output: 0

Example 2:

Input:
         3
       /   \
      2     5
    /   \
   1     4
target = 4
Output: 2
Your Task:
 You don't have to take input. Just complete the function getLevel() that takes a node and a target as parameters and returns the level of the target value. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= Number of nodes<= 10ˆ5
1 <= Data of a node<= 10ˆ5
1 <= Target <= 10ˆ5
  ****/

/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/

// function should return level of the target node
int getLevel(struct Node *node, int target)
{
    if(!node) return 0;

    if(node->data == target) return 1;

    int ret = getLevel(node->left, target);
    if(ret) return ret+1;

    ret = getLevel(node->right, target);
    if(ret) return ret+1;

    return 0;
}

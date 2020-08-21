/****
Given a Binary Tree and a target key, you need to find all the ancestors of the given target key.

              1
            /   \
          2      3
        /  \
      4     5
     /
    7
Key: 7
Ancestor: 4 2 1
Example 1:

Input:
        1
      /   \
     2     3
target = 2
Output: 1

Example 2:

Input:
         1
       /   \
      2     3
    /  \   /  \
   4    5 6    8
  /
 7
target = 7
Output: 4 2 1
 

Your Task:
Your task is to complete the function Ancestors() that finds all the ancestors of the key in the given binary tree.
Note:
The return type is
cpp: vector<int>
Java: ArrayList<Integer>
python: list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= N <= 1000
1<= data of node <= 10000
  ****/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

bool getAncestors(Node* root, int target, vector<int>& res)
{
    if(!root) return false;
    if(root->data == target) return true;

    bool ret = getAncestors(root->left, target, res);
    if(ret) { res.push_back(root->data); return true; }

    ret = getAncestors(root->right, target, res);
    if(ret) { res.push_back(root->data); return true; }

    return false;
}
// Function should return all the ancestor of the target node
vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> res;
    getAncestors(root, target, res);
    return res;
}

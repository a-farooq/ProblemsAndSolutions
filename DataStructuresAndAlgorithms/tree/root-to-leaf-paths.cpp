/****
Given a Binary Tree of size N, you need to find all the possible paths from root node to all the leaf node's of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 1 2 #1 3 #
Explanation: 
All possible paths:
1->2
1->3

Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 10 20 40 #10 20 60 #10 30 #

Your Task:
Your task is to complete the function Paths() that takes the root node as an argument and return all the possible path. (All the path are printed '#' separated by the driver's code.)

Note: The return type
cpp: vector<vector<int>
java: ArrayList<ArrayList<Integer>>
python: list of list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1<=N<=10ˆ3
  ****/

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

void getPath(Node* root, vector<int> path, vector<vector<int>>&res)
{
    if(!root) return;
    path.push_back(root->data);
    if(!root->left && !root->right)
        res.push_back(path);

    getPath(root->left, path, res);
    getPath(root->right, path, res);
}

/* The function should print all the paths from root
 to leaf nodes of the binary tree */
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> res;
    vector<int> path;
    getPath(root, path, res);

    return res;
}

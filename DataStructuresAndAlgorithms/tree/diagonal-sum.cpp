/****
Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. Given a Binary Tree of size N, print all diagonal sums.

For the following input tree, output should be 9, 19, 42.
9 is sum of 1, 3 and 5.
19 is sum of 2, 6, 4 and 7.
42 is sum of 9, 10, 11 and 12.

DiagonalSum

Example 1:

Input:
         4
       /   \
      1     3
           /
          3
Output: 7 4 
Example 2:

Input:
           10
         /    \
        8      2
       / \    /
      3   5  2
Output: 12 15 3 
Your Task:
You don't need to take input. Just complete the function diagonalSum() that takes root node of the tree as parameter and returns an array containing the diagonal sums for every diagonal present in the tree with slope -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of nodes<=10^5

https://practice.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1
  ****/

/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

void diagonalSumUtil(Node* root, int diag, map<int,int>&mp)
{
    if(!root) return;

    mp[diag] += root->data;

    diagonalSumUtil(root->left, diag+1, mp);
    diagonalSumUtil(root->right, diag, mp);
}
vector <int> diagonalSum(Node* root)
{
    vector<int> vec;
    map<int,int> mp;
    int diag=0;
    diagonalSumUtil(root, diag, mp);
    for(auto it = mp.begin(); it != mp.end(); it++)
        vec.push_back(it->second);
    return vec;
}

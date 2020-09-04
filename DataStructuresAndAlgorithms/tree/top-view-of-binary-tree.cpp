/****
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Print from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3

Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
Your Task:
Since this is a function problem. You don't have to take input. Just complete the function printTopView() that takes root node as parameter and prints the top view. The newline is automatically appended by the driver code.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= Node Data <= 105

Solution: very similar to bottom view of binary tree
Can be solved with queue as well instead of recursion
  ****/

//top view will show at most 2 nodes from each level
//and 1 node from each horizontal distance
void topViewUtil(Node* root, int hd, int level, map<int,pair<int,int>>& hash)
{
    if(!root) return;

    auto iter = hash.find(hd);
    if(iter != hash.end()) {
        //if 2 nodes have same hd, one with lower level must be saved
        int lvl = (iter->second).second;

        if(level < lvl) {
            hash.erase(hd);
            hash.emplace(hd, make_pair(root->data, level));
        }
    }
    else {
        hash.emplace(hd, make_pair(root->data, level));
    }

    topViewUtil(root->left, hd-1, level+1, hash);
    topViewUtil(root->right, hd+1, level+1, hash);
}

// function should print the topView of the binary tree
void topView(struct Node *root)
{
    map<int, pair<int,int>> hash;
    topViewUtil(root, 0, 0, hash);
    for(auto iter = hash.begin(); iter != hash.end(); iter++)
    {
        cout << iter->second.first << " ";
    }
}


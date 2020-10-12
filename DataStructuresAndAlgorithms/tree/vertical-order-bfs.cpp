/****
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:

Input:
     2
      \
       3
      /
     4
Output: 2 4 3

Example 2:

Input:
       1
    /    \
   2      3
 /   \      \
4     5      6
Output: 4 2 1 5 3 6

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticalOrder() which takes the root node as input and returns an array containing the vertical order traversal of the tree from the leftmost to the rightmost level. If 2 nodes lie in the same vertical level, they should be printed in the order they appear in the level order traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 5000
  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
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

void verticalOrderBFS(Node* root, vector<int>&out)
{
    queue<pair<Node*,int>> q;
    q.push(make_pair(root, 0));
    map<int,vector<int>>mp;

    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        Node* node = p.first;
        int hd = p.second;
        q.pop();
        mp[hd].push_back(node->data);

        if(node->left) q.push(make_pair(node->left, hd-1));

        if(node->right) q.push(make_pair(node->right, hd+1));
    }

    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        out.insert(out.end(), it->second.begin(), it->second.end());
    }
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    vector<int> vec;

    verticalOrderBFS(root, vec);

	return vec;
}

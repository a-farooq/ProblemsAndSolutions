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

void verticalOrderDFS(Node* root, int hd, int lvl, map<int,map<int,vector<int>>>&mp)
{
    if(!root) return;

    if(mp.find(hd)!=mp.end()) {
        //map of level vs data (at same hd)
        map<int,vector<int>>&lvlmap = mp[hd];
        lvlmap[lvl].push_back(root->data);
    }
    else {
        //map of level vs data (at same hd)
        map<int,vector<int>> lvlmap;
        lvlmap[lvl].push_back(root->data);
        mp[hd] = lvlmap;
    }

    verticalOrderDFS(root->left, hd-1, lvl+1, mp);
    verticalOrderDFS(root->right, hd+1, lvl+1, mp);
}

// root: root node of the tree
vector<int> verticalOrder(Node *root)
{
    vector<int> vec;

	//map of hd vs map of lvl vs data vector
    map<int,map<int,vector<int>>> hash;
    verticalOrderDFS(root, 0, 0, hash);
    for(auto it1 = hash.begin(); it1 != hash.end(); it1++)
    {
        auto it2=it1->second.begin();
        for(; it2 != it1->second.end(); it2++) {
            //cout << *(it2->second.begin()) << endl;
            vec.insert(vec.end(), it2->second.begin(), it2->second.end());
        }
    }
    return vec;
}

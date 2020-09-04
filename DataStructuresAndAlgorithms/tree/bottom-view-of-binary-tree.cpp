/****
Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

                      20
                    /    \
                  8       22
                /   \        \
              5      3       25
                    /   \      
                  10    14

For the above tree, the bottom view is 5 10 3 14 25.
If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree the output should be 5 10 4 14 25.
 

Example 1:

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation:
First case represents a tree with 3 nodes
and 2 edges where root is 1, left child of
1 is 3 and right child of 1 is 2.

Thus nodes of the binary tree will be
printed as such 3 1 2.
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Your Task:
This is a functional problem, you don't need to care about input, just complete the function bottomView() which takes the root node of the tree as input and returns an array containing the bottom view of the given tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5




Method 1 – Using Queue:
The following are steps to print Bottom View of Binary Tree.
1. We put tree nodes in a queue for the level order traversal.
2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1.
3. Also, use a TreeMap which stores key value pair sorted on key.
4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal distance as key. For the first time it will add to the map, next time it will replace the value. This will make sure that the bottom most element for that horizontal distance is present in the map and if you see the tree from beneath that you will see that element.


OR

Method 2 (Using HashMap):
Create a map like, map where key is the horizontal distance and value is a pair(a, b) where a is the value of the node and b is the height of the node. Perform a pre-order traversal of the tree. If the current node at a horizontal distance of h is the first we’ve seen, insert it in the map. Otherwise, compare the node with the existing one in map and if the height of the new node is greater, update in the Map.
  ****/

/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

void bottomViewUtil(Node* root, int hd, int level, map<int,pair<int,int>>& hash)
{
    if(!root) return;
    
    auto iter = hash.find(hd);
    if(iter != hash.end()) {
        int lvl = (iter->second).second;
        if(level >= lvl) {
            hash.erase(hd);//map doesnt overwrite a key record, so delete first
            //hash.insert(make_pair(hd, make_pair(root->data, level)));
            hash.emplace(hd, make_pair(root->data, level));
        }
    }
    else {
        hash.emplace(hd, make_pair(root->data, level));
    }
    
    bottomViewUtil(root->left, hd-1, level+1, hash);
    bottomViewUtil(root->right, hd+1, level+1, hash);
}
// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    vector<int> res;
    map<int, pair<int,int>> hash;
    bottomViewUtil(root, 0, 0, hash);
    for(auto iter = hash.begin(); iter != hash.end(); iter++)
    {
        //cout << iter->second << " ";
        res.push_back(iter->second.first);
    }
    return res;
}

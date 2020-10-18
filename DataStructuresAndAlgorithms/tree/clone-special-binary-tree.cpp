/****
Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.

Example 1:

Input:

Output: 1
Explanation: The tree was cloned successfully.

Your Task:
No need to read input or print anything. Complete the function cloneTree() which takes root of the given tree as input parameter and returns the root of the cloned tree. 

Note: The output is 1 if the tree is cloned successfully. Otherwise output is 0.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000
  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

void createMap(Node* r1, unordered_map<Node*, Node*>&um)
{
    if(!r1)
        return;

    um[r1]=(new Node(r1->data));

    createMap(r1->left, um);
    createMap(r1->right, um);
}
/* The function should clone the passed tree and return
   root of the cloned tree */
Node* cloneTree(Node* r1)
{
   //Your code here
   unordered_map<Node*, Node*> umap;
   Node* root;
   createMap(r1, umap);
   for(auto iter : umap) {
        auto l_iter = umap.find(iter.first->left);
        if(l_iter != umap.end())
            iter.second->left = l_iter->second;

        auto r_iter = umap.find(iter.first->right);
        if(r_iter != umap.end())
            iter.second->right = r_iter->second;

        auto x_iter = umap.find(iter.first->random);
        if(x_iter != umap.end())
            iter.second->random = x_iter->second;
   }
   return umap[r1];
}


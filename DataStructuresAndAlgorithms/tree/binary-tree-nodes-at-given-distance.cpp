/****
Given a binary tree, a target node in the binary tree, and an integer value k, find all the nodes that are at distance k from the given target node. No parent pointers are available.

Example 1:

Input :      
          20
        /    \
      8       22 
    /   \
   4    12 
       /   \
      10    14

Target Node = 8
K = 2

Output: 10 14 22

Explanation: The three nodes at distance 2
from node 8 are 10, 14, 22.



Example 2:

Input :      
         20
       /    \
      7      24
    /   \
   4     3
        /  
       1    

Target Node = 7
K = 2

Output: 1 24

Your Task:  
You dont need to read input or print anything. Complete the function KDistanceNodes() which takes the root of the tree, target and K as input parameters and returns a list of nodes at k distance from target. 


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^3
1 ≤ data of node ≤ 10000
1 ≤ target ≤ 10000
1 ≤ k ≤ 20
  ****/

/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class solver
{
private:

    vector<int> res;

    void findKDistanceNodesDown(Node* root, int k)
    {
        if(!root)
            return;

        if(k==0)
            res.push_back(root->data);

        findKDistanceNodesDown(root->left, k-1);

        findKDistanceNodesDown(root->right, k-1);
    }

    int KDistanceNodesUtil(Node* root, int target, int k)
    {
        if(!root)
            return -1;

        if(root->data == target) {
            findKDistanceNodesDown(root, k);
            return 0;
        }

        int ld = KDistanceNodesUtil(root->left, target, k);
        if(ld>=0) {
            if(ld+1==k)
                res.push_back(root->data);

            else findKDistanceNodesDown(root->right, k-ld-2);

            return 1+ld;
        }

        int rd = KDistanceNodesUtil(root->right, target, k);
        if(rd>=0) {
            if(rd+1==k)
                res.push_back(root->data);

            else findKDistanceNodesDown(root->left, k-rd-2);

            return 1+rd;
        }
    }
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        res.clear();
        KDistanceNodesUtil(root, target, k);
        sort(res.begin(), res.end());
        return res;
    }
};

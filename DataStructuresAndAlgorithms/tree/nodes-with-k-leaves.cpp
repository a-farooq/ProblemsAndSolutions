/****
Given a binary tree and a integer value K, the task is to find all nodes data in given binary tree having exactly K leaves in sub-tree rooted with them.

NOTE: Nodes should be printed in the order in which they appear in postorder traversal.

Example 1:

Input:
K = 1
      0
    /   \
   1     2
Output: -1
Explanation: There is no node in this
tree which has one leaf in the sub tree
below it.
Example 2:

Input:
K = 2
          0
        /   \
       1     2
           /  
          4
        /   \
       5     9
Output: 4 2
Explanation: Nodes with data 2 and 4, have
2 leaves in the subtree below it.
Your Task:
Just complete the function btWithKleaves() and returns the answer (as a vector<int> in cpp, as a ArrayList<Integer> in java and as list in python)

Note: If no node is found the list returned should contain only one value -1.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 1000
1 <= K <= 1000
1 <= value of nodes <= 10000


  ****/

/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};
*/


int btWithKleavesUtil(Node* root, int k, vector<int>& out)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return 1;

    int lc = btWithKleavesUtil(root->left, k, out);
    int rc = btWithKleavesUtil(root->right, k, out);

    if(lc+rc==k)
        out.push_back(root->data);

    return lc+rc;
}
/*You are required to complete below method */

vector<int> btWithKleaves(Node *ptr, int k)
{
    //your code here.
    vector<int> vec;
    btWithKleavesUtil(ptr, k, vec);
    if(vec.empty())
        vec.push_back(-1);
    return vec;
}

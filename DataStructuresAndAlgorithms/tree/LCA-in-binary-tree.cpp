/****
Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them is present. 

Example 1:

Input:
n1 = 2 , n2 =  3

     1
   /  \
  2    3
Output: 1

Example 2:

Input:
n1 = 3 , n2 = 4

         5
        /
       2
     /  \
    3    4
Output: 2
Your Task:
 Just complete the function lca() that takes nodes, n1, and n2 as parameters and returns LCA node as output.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree.

Constraints:
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000

  ****/

/* A binary tree node

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

/* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return
   NULL. Else if left subtree contains any
   of them return pointer to left.*/

bool lcaUtil(Node* root, int n, vector<Node*> vec, vector<Node*>& out)
{

    if(!root) return false;

    if(root->data == n) {
        vec.push_back(root);
        out.insert(out.end(), vec.begin(), vec.end());
        return true;
    }

    vec.push_back(root);

    if(lcaUtil(root->left, n, vec, out)) return true;
    if(lcaUtil(root->right, n, vec, out)) return true;

    return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root) return nullptr;

    vector<Node*> vec1, vec2, vec;
    bool res1 = lcaUtil(root, n1, vec, vec1);
    bool res2 = lcaUtil(root, n2, vec, vec2);

    if(!res1 && !res2) return nullptr;

    //for(auto val : vec1) cout << val->data << " "; cout <<  endl;
    //for(auto val : vec2) cout << val->data << " "; cout <<  endl;

    Node* prev = vec1[0];
    for(auto i = 1, j = 1; i < vec1.size() && j < vec2.size(); i++, j++)
    {
        if(vec1[i] != vec2[j])
            break;
        prev = vec1[i];
    }
    return prev;
}

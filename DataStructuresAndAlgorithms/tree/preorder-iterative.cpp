/****
Given a binary tree, find its preorder traversal.

Example 1:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 
Example 2:

Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^4
1 <= Data of a node <= 10^5


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

vector<int> preorder(Node* root)
{
    vector<int> vec;
    stack<Node*> stk;

    Node* node = root;
    while(!stk.empty() || node)
    {
        while(node) {
            vec.push_back(node->data);
            stk.push(node);
            node = node->left;
        }
        if(!stk.empty())
        {
            //vec.push_back(stk.top()->data);
            node = stk.top()->right;
            stk.pop();
        }
    }
    return vec;
}

void preorderUtil(Node* root, vector<int> &vec)
{
  // Your code here
    if(!root) return;

    vec.push_back(root->data);
    preorderUtil(root->left, vec);
    preorderUtil(root->right, vec);
}

vector <int> preorder_rec(Node* root)
{
  // Your code here
    vector<int> vec;
    preorderUtil(root, vec);
    return vec;
}

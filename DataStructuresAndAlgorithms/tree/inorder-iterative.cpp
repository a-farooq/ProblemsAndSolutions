/****
Given a Binary Tree, find the In-Order Traversal of it.

Example 1:

Input:
       1
     /  \
    3    2
Output: 3 1 2

Example 2:

Input:
        10
     /      \ 
    20       30 
  /    \    /
 40    60  50
Output: 40 20 60 10 50 30

Your Task:
You don't need to read input or print anything. Your task is to complete the function inOrder() that takes root node of the tree as input and returns a list containing the In-Order Traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^5
1 <= Data of a node <= 10^5

  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

vector<int> inOrder(Node* root)
{
    vector<int> vec;
    stack<Node*> stk;

    Node* node = root;
    while(!stk.empty() || node)
    {
        while(node) {
            stk.push(node);
            node = node->left;
        }
        if(!stk.empty())
        {
            vec.push_back(stk.top()->data);
            node = stk.top()->right;
            stk.pop();
        }
    }
    return vec;
}

// Return a vector containing the inorder traversal of the tree
vector<int> inOrder_rec(Node* root)
{
  // Your code here
    vector<int> vec;
    if(root == NULL) return vec;

    vec = inOrder_rec(root->left);
    vec.push_back(root->data);

    vector<int> tmp = inOrder_rec(root->right);
    vec.insert(vec.end(), tmp.begin(), tmp.end());
    //for(auto i : tmp) vec.push_back(i);

    return vec;
}

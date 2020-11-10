/****
Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:  5 10 39 1

        1
     /     \
   10     39
  /
5

Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19

Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11
Your Task:
You don't need to read input or print anything. Your task is to complete the function postOrder() that takes root node as input and returns an array containing the postorder traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000


  ****/

//User function Template for C++

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

vector <int> postOrder(Node* root)
{
    vector<int> vec;
    stack<Node*> stk;
    do
    {
        while(root) {
            if(root->right)
                stk.push(root->right);
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();

        if(root->right && !stk.empty() && stk.top() == root->right)
        {
            stk.pop();
            stk.push(root);
            root = root->right;
        }
        else {
            vec.push_back(root->data);
            root = nullptr;
        }
    } while(!stk.empty());

    return vec;
}

vector <int> postorder_rec(Node* root)
{
  // Your code here
    vector<int> vec;
    if(root == NULL) return vec;

    vec = postorder_rec(root->left);

    vector<int> tmp = postorder_rec(root->right);
    vec.insert(vec.end(), tmp.begin(), tmp.end());
    //for(auto i : tmp)  vec.push_back(i);

    vec.push_back(root->data);
    return vec;
}

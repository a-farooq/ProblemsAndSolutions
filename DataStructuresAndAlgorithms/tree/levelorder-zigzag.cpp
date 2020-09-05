/****
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Example 1:

Input:
        3
      /   \
     2     1
Output: 3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output: 7 9 7 8 8 6 9 10
Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.
For Example: For the below binary tree the zigzag order traversal will be 1 3 2 7 6 5 4. Binary Tree Example

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10^4
  ****/

//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root)
{
    vector<int> vec;

    stack<Node*> stk_lt;
    stack<Node*> stk_rt;
    if(root)
        stk_rt.push(root);

    while(!stk_lt.empty() || !stk_rt.empty()) {
        while(!stk_lt.empty()) {
            Node* top = stk_lt.top();
            vec.push_back(top->data);
            stk_lt.pop();

            if(top->right)
                stk_rt.push(top->right);
            if(top->left)
                stk_rt.push(top->left);
        }

        while(!stk_rt.empty()) {
            Node* top = stk_rt.top();
            vec.push_back(top->data);
            stk_rt.pop();

            if(top->left)
                stk_lt.push(top->left);
            if(top->right)
                stk_lt.push(top->right);
        }
    }
    return vec;
}

/****
Complete the function to print spiral order traversal of a tree. For below tree, function should print 1, 2, 3, 4, 5, 6, 7.


 
 

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function printSpiral() which prints the elements in spiral form of level order traversal. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 10ˆ5
1 <= Data of a node <= 10ˆ5
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
}; */

void printSpiral(Node *root)
{
    if(!root) return;

    stack<Node*> stk1, stk2;
    cout << root->data << " ";
    stk1.push(root);

    while(!stk1.empty() || !stk2.empty())
    {
        while(!stk1.empty())
        {
            Node* n = stk1.top();
            stk1.pop();
            if(n->left) {
                cout << n->left->data << " ";
                stk2.push(n->left);
            }
            if(n->right) {
                cout << n->right->data << " ";
                stk2.push(n->right);
            }
        }

        while(!stk2.empty())
        {
            Node* n = stk2.top();
            stk2.pop();
            if(n->right) {
                cout << n->right->data << " ";
                stk1.push(n->right);
            }
            if(n->left) {
                cout << n->left->data << " ";
                stk1.push(n->left);
            }
        }
    }
    //cout << endl;
}

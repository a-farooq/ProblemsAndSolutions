/****
Given a BST and a value x, the task is to delete the nodes having values greater than or equal to x.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case consists of an integer N. Then in the next line are N space separated values of the BST nodes. In the next line is an integer x representing the value of the node in the BST.

Output Format:
For each test case, in a new line, print the inorder traversal after deletions.

Constraints:
1 <= T <= 100
1 <= N <= 10^3
1 <= A[] <= 10^3
1 <= x <= N

Example:
Input:
2
7
20 8 22 4 12 10 14
8
7
20 8 22 4 12 10 14
10
Output:
4
4 8

Solution:
1. Do postorder traversal left to right
2. if any node is found greater than key, send its left child to parent and delete right child and itself
  ****/

/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

/*The function should return the root of the modified tree*/
Node* deleteNode(Node* root, int key)
{
    if(!root) return nullptr;

    //if(root->data <= key) {
    //    return root->left;
    //}
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);

    if(root->data>=key) {
        //return root->left;
        Node* temp=root->left;
        if(root->right) {
            delete root->right;
        }
        if(root) delete root;

        return temp;
    }
    return root;
}

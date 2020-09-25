/****
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List strating from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3

Your Task:  
You dont need to read input or print anything. Complete the function convertToDLL() which takes root of the given tree as input parameter and returns the head of the doubly link list.

Note:
The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 10^4
  ****/

/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/


bool convertToDLLUtil(Node* root, Node** head)
{
    if(!root)
        return false;

    if(!root->left && !root->right) {
        if(*head) {
            (*head)->left = root;
        }
        root->right = *head;
        *head = root;
        return true;
    }

    bool ret = convertToDLLUtil(root->right, head);
    if(ret) {
        root->right = nullptr;
    }

    ret = convertToDLLUtil(root->left, head);
    if(ret) {
        root->left = nullptr;
    }

    return false;
}

Node* convertToDLLUtil2(Node* root, Node** head)
{
    if(!root)
        return nullptr;

    if(!root->left && !root->right) {
        if(*head) {
            (*head)->left = root;
        }
        root->right = *head;
        *head = root;
        //return true;
        return nullptr;
    }

    root->right = convertToDLLUtil2(root->right, head);
    //if(ret) {
    //    root->right = nullptr;
    //}

    root->left = convertToDLLUtil2(root->left, head);
    //if(ret) {
    //    root->left = nullptr;
    //}

    return root;
}
// return the head of the DLL and remove those node from the tree as well.
Node * convertToDLL(Node *root)
{
    Node* head = nullptr;
    convertToDLLUtil2(root, &head);
    head->left = nullptr;
    return head;
}

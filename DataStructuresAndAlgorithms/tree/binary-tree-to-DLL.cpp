/****
Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

TreeToList

Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
Your Task:
You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL . The driver code prints the DLL both ways.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(H).
Note: H is the height of the tree and this space is used implicitly for recursion stack.

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000

Algorithm:
Do reverse inorder and assign each root as head of dll
  ****/

/* Structure for tree and linked list

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

void bToDLLUtil(Node* root, Node** head)
{
    if(!root) return;

    static Node* prev = nullptr;

    bToDLLUtil(root->right, head);

    root->right = *head;

    if(*head != nullptr)
        (*head)->left = root;

    *head = root;

    bToDLLUtil(root->left, head);
}
// This function should return head to the DLL

Node * bToDLL(Node *root)
{
    Node* head = nullptr;

    bToDLLUtil(root, &head);

    return head;
}

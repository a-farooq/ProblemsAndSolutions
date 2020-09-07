/****
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10

Your Task:
You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.


Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H) , where H is the height of the tree.


Constraints:
1 <= N <= 1000
1 <= K <= N

Solution:
The idea is to do reverse inorder traversal of BST. The reverse inorder traversal traverses all nodes in decreasing order. While doing the traversal, we keep track of count of nodes visited so far. When the count becomes equal to k, we stop the traversal and print the key.
  ****/

/*The Node structure is defined as
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

int reverseInorder(Node* root, int& k)
{
    if(!root)   return 0;


    int ret = reverseInorder(root->right, k);
    if(!k) return ret; //break the traversal

    //change after visiting only right child
    if(--k==0) {
        //cout << root->data << endl;
        return root->data;
    }

    ret = reverseInorder(root->left, k);
    if(!k) return ret; //break the traversal

    return ret;
}

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    return reverseInorder(root, K);
}

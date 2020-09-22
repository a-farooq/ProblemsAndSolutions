/****
Given a Binary Search Tree and a target sum. Check whether there's a pair of Nodes in the BST with value summing up to the target sum. 

Example 1:

Input:
        2
      /   \
     1     3
sum = 5
Output: 1
Example 2:

Input:
           6
          /    
         5     
        /
       3 
     /  \
    1    4
sum = 2
Output: 0
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isPairPresent() that takes a root node and a target value as a parameter and returns 1 if there's a pair of Nodes in the BST with values summing up to the target sum, else returns 0. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1<=Number of Nodes<=100000
1<=K<=1000005

Algorithm:
The inorder traversal of a BST gives us the keys in sorted order.
Hence, you can generate a sorted array of keys and the question then reduces to finding the pair sum in a sorted array.
The O(N) solution for this is pretty straightforward using 2-pointers.

But, storing all the keys in an array requires O(N) extra space. Can you use the same idea of the 2-pointers without actually storing the node values in an array? What about doing an iterative in-order traversal of the tree, one normal and the other reverse?
  ****/

/*Complete the function below
Node is as follows
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

void inorder(Node* root, vector<int>& out)
{
    if(!root) return;

    inorder(root->left, out);
    out.push_back(root->data);
    inorder(root->right, out);

}
// root : the root Node of the given BST
// target : the target sum
int isPairPresent(struct Node *root, int target)
{
//add code here.
    vector<int> vec;
    inorder(root, vec);

    int i=0, j=vec.size()-1;
    while(i<j) {
        if(vec[i]+vec[j]==target)
            return 1;
        else if(vec[i]+vec[j]<target)
            i++;
        else j--;
    }
    return 0;
}

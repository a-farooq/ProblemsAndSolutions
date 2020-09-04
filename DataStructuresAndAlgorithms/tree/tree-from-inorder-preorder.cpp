/****
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000


  ****/

/*Complete the code here.
Node is as follows:

struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int a) {
      data = a;
      left=nullptr;
      right=nullptr;
  }
};*/


//int preIndex = 0;

int findroot(int a[], int start, int end, int x)
{
    for(int i=start; i <= end; i++)
        if(a[i]==x) return i;
}

Node* buildUtil(int in[], int pre[], int start, int end, int& preIndex)
{
    if(start > end) return nullptr;

    Node* node = new Node(pre[preIndex++]);

    if(start == end) return node;

    int rootInIdx = findroot(in, start, end, node->data);

    //if(rootInIdx <= end) {
        node->left = buildUtil(in, pre, start, rootInIdx-1, preIndex);

        node->right = buildUtil(in, pre, rootInIdx+1, end, preIndex);
    //}
    return node;
}
Node* buildTree(int in[],int pre[], int n)
{
    Node* root = nullptr;
    int preIndex=0;
    //build(root, in, pre, n, 0);
    root = buildUtil(in, pre, 0, n-1, preIndex);
    return root;
}

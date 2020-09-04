/****
Write a function to print Boundary Traversal of a binary tree. Boundary Traversal of a binary tree here means that you have to return boundary nodes of the binary tree Anti-Clockwise starting from the root.
Note: Boundary node means nodes present at the boundary of left subtree and nodes present at the right subtree also including leaf nodes.
For the below tree, the function should print 20 8 4 10 14 25 22 .
    
                         

Example 1:

Input:
        1
      /   \
     2    3       
Output: 1 2 3
Explanation:

The first test case represents a tree
with 3 nodes and 2 edges where the
root is 1, the left child of 1 is 2
and the right child of 1 is 3. And
boundary traversal of this tree
prints nodes as 1 2 3.

Example 2:

Input:
          10
        /   \
       20   30
     /   \
    40   60
Output: 10 20 40 60 30

Your Task:
This is a function problem. You don't have to take input. Just complete the function printBoundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

Expected Time Complexity: O(N). 
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes<= 10^5
1 <= Data of a node<= 10^5

Solution:
https://xiaoguan.gitbooks.io/leetcode/content/LeetCode/545-boundary-of-binary-tree-medium.html

  ****/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void leftBoundary(Node* root, vector<int>& vec)
{
    if(!root) return;
    
    if(root->left) {
        vec.push_back(root->data);
    
        leftBoundary(root->left, vec);
    }
    else if(root->right) {
        vec.push_back(root->data);
    
        leftBoundary(root->right, vec);
    }
}

void printBoundaryUtil(Node* root, vector<int>& out)
{
    if(!root) {
        //leftboundary = false;
        //out.insert(out.end(), vec.begin(), vec.end());
        return;
    }
    
    printBoundaryUtil(root->left, out);
    
    if(!root->left && !root->right) {
        out.push_back(root->data);
        //leftboundary = false;
        return;
    }
    
    //if(leftboundary)
    //    out.push_back(root->data);
    
    
    printBoundaryUtil(root->right, out);

}

void rightBoundary(Node* root, vector<int>& vec)
{
    if(!root) return;
    
    if(root->right) {
        rightBoundary(root->right, vec);
        vec.push_back(root->data);
    }
    else if(root->left) {
        rightBoundary(root->left, vec);
        vec.push_back(root->data);
    }
}
vector <int> printBoundary(Node *root)
{
    vector<int> vec;
    
    vec.push_back(root->data);
    
    leftBoundary(root->left, vec);
    
    printBoundaryUtil(root, vec);
    
    rightBoundary(root->right, vec);
    //vec.pop_back();
    
    return vec;
}

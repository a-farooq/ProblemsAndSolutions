/****
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.

Example 1:

Input:
            1
          /   \
         2     3

Output: -4

Explanation:
sum at odd levels - sum at even levels
= (1)-(2+3) = 1-5 = -4

Example 2:

Input:
            10
          /    \
        20      30
       /  \         
     40    60      

Output: 60

Explanation:
sum at odd levels - sum at even levels
= (10+40+60) - (20+30)
= 110 - 50
= 60

Your Task:  
You dont need to read input or print anything. Complete the function getLevelDiff() which takes root node as input parameter and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^5
  ****/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

void diffUtil(Node* root, int level, pair<int,int>& sum)
{
    if(!root) return;

    if(level&1) sum.first += root->data;
    else sum.second += root->data;

    diffUtil(root->left, level+1, sum);
    diffUtil(root->right, level+1, sum);
}
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
    pair<int, int> sum(0,0);
    diffUtil(root, 1, sum);
    return sum.first-sum.second;
}

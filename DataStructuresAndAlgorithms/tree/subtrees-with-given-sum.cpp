/****
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).
Example 2:

Input:
    1
  /  \
 2    3
X = 5
Output: 0
Explanation: No subtree has sum equal
to 5.
Your Task:
You don't need to read input or print anything. Your task is to complete the function countSubtreesWithSumX() which takes the root node and an integer X as inputs and returns the number of subtrees of the given Binary Tree having sum exactly equal to X.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= N <= 10^3
-10^3 <= Node Value <= 10^3

  ****/

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

int countSubtreesWithSum(Node* root, int X, int& cnt)
{
    if(!root)
	    return 0;

	int lsum = countSubtreesWithSum(root->left, X, cnt);

	int rsum = countSubtreesWithSum(root->right, X, cnt);

	int sum= lsum+rsum+root->data;

	if(sum==X)
	    cnt++;

	return sum;
}
// your are required to complete this function
// function should return the count of the number of
// subtrees with Sum equal to X
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int cnt=0;

	countSubtreesWithSum(root, X, cnt);

	return cnt;
}

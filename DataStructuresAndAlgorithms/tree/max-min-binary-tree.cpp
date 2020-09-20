/****
Given a Binary Tree, find maximum and minimum elements in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges. The following line contains the edges as shown in the example.

Output:
Print two space-separated integers maximum and minimum element in the binary tree.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=data of the node<=10^5

Example:
Input:
1
7
2 7 L 2 5 R 7 6 R 6 1 L 6 11 R 5 9 R 9 4 L

Output:
11 1

Explanation:

                                                       

The above tree is constructed through the example in the input. The maximum and minimum element in this binary tree is 11 and 1 respectively.


  ****/

// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
// Your code goes here
    if(!root) return 0;

    int lv = findMax(root->left);
    int rv = findMax(root->right);

    return max(max(lv,rv),root->data);
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
// Your code goes here
    if(!root) return INT_MAX;

    int lv = findMin(root->left);
    int rv = findMin(root->right);

    return min(min(lv,rv),root->data);
}

/****
Given a full binary expression tree consisting of basic binary operators (+ , – ,*, /) and some integers, Your task is to evaluate the expression tree.

Example 1:

Input: 
              +
           /     \
          *       -
        /  \    /   \
       5    4  100  20 

Output: 100

Explanation:
((5 * 4) + (100 - 20)) = 100

Example 2:

Input:
            -
          /   \
         4     7

Output: -3

Explanation:
4 - 7 = -3

Your Task:  
You dont need to read input or print anything. Complete the function evalTree() which takes root node as input parameter and returns an integer denoting the result obtained by simplifying the expression tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ N ≤ 500
  ****/

/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

/*You are required to complete below method */
int evalTree(node* root)
{
    if(!root) return 0;

    if(!root->left && !root->right)
        return stoi(root->data);

    int ldata = evalTree(root->left);
    int rdata = evalTree(root->right);

    int res = 0;
    char op = (root->data)[0];
    switch(op) {
        case '+': res = ldata+rdata; break;
        case '-': res = ldata-rdata; break;
        case '*': res = ldata*rdata; break;
        case '/': res = ldata/rdata; break;
    }
    return res;
}

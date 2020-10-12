/****
Given a Binary Tree of size N, Print the corner nodes ie- the node at the leftmost and rightmost of each level.

Example 1:

Input :
         1
       /  \
     2      3
    / \    / \
   4   5  6   7    

Output: 1 2 3 4 7

Explanation:
Corners at level 0: 1
Corners at level 1: 2 3
Corners at level 2: 4 7

Example 2:

Input:

        10
      /    \
     20     30
    / \  
   40  60

Output: 10 20 30 40 60

Your Task:  
You dont need to read input or print anything. Complete the function printCorner() which takes root node as input parameter and prints the corner nodes separated by spaces. The left corner should be printed before the right for each level starting from level 0.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(number of nodes in a level)


Constraints:
1 ≤ N ≤ 10^5
  ****/

/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{

// Your code goes here
    if(!root) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        int i=0;
        while(i < size) {
            root = q.front();
            q.pop();

            if(i==0 || i==size-1) {
                cout << root->data << " ";
            }

            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);

            i++;
        }

    }
    //cout << endl;

}

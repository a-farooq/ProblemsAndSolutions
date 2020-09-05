/****
Given a Binary Tree having positive and negative nodes. Find the maximum sum of a level in the given Binary Tree.

Example 1:

Input :               
             4
          /    \
         2     -5
        / \    / \
      -1   3  -2  6

Output: 6

Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

Example 2:

Input :          
            1
          /   \
         2     3
        / \     \
       4   5     8
                / \
               6   7  

Output :  17

Explanation: Maximum sum is at level 2.

Your Task:  
You dont need to read input or print anything. Complete the function maxLevelSum() which takes root node as input parameter and returns the maximum sum of any horizontal level in the given Binary Tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 10^4
  ****/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void maxLevelSumUtil(Node* root, int level, unordered_map<int,int>&um)
{
    if(!root) return;

    um[level] += root->data;
    //um[0] = max(um[0], um[level]);
    //cout << "data: "<<root->data<<", level0: "<<um[0]<<", level: "<<level<<", "<< um[level]<< endl;

    maxLevelSumUtil(root->left, level+1, um);
    maxLevelSumUtil(root->right, level+1, um);
}

/*You are required to complete below method */
int maxLevelSum(Node* root)
{
    unordered_map<int,int> um;
    int maxi = INT_MIN;
    maxLevelSumUtil(root, 1, um);
    for(auto iter = um.begin(); iter != um.end(); iter++) {
        //cout << iter->first << ", " << iter->second << endl;
        maxi = max(maxi, iter->second);
    }
    return maxi;
}

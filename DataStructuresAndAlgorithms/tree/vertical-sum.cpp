/****
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
Your Task:
You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of nodes<=1000


  ****/

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

void verticalSumUtil(Node* root, int hd, map<int,int>& hash)
{
    if(!root) return;

    hash[hd] += root->data;

    verticalSumUtil(root->left, hd-1, hash);
    verticalSumUtil(root->right, hd+1, hash);
}
vector <int> verticalSum(Node *root)
{
    int hd=0;
    vector<int> vec;
    map<int,int> hash;
    verticalSumUtil(root, hd, hash);
    for(auto iter=hash.begin(); iter != hash.end(); iter++) {
        vec.push_back(iter->second);
    }
    return vec;
}

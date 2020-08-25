/****
Given a Binary Tree of size N, your task is to complete the function minLeafSum(), that should return the sum of all the leaf nodes that are at minimum level of the given binary tree.
Example:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \ 
 7    2      
Output :
sum = 5 + 8 = 13
Input:
The function takes a single arguments as input, the reference pointer to the root of the binary tree.
There are T test cases and for each test case the function will be called separately.

Output:
The function should return the sum of all the leaf nodes that are at the minimum level of the binary tree.

Constraints:
1<=T<=10ˆ3
0<=N<=10ˆ3

Example:
Input:
2
2
1 2 L 1 3 R
5
10 20 L 10 30 R 20 40 L 20 60 R 30 90 L
Output:
5
190


  ****/

/*
Structure of the Node of the tree is
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// Your task is to complete this function
// function shoudl return the required sum
int minLeafSum(Node* root)
{
    if(!root) return 0;

    int sum = 0;
    bool lastlevel = false;

    queue<Node*> levelq;
    levelq.push(root);
    levelq.push(nullptr);

    while(!levelq.empty())
    {
        Node* n = levelq.front();
        levelq.pop();

        //cout << n->data << endl;

        if(n==nullptr) {
            if(levelq.empty() || lastlevel) break;
            levelq.push(nullptr);
        }
        else {
            if(!n->left && !n->right) {
                sum += n->data;
                lastlevel = true;
                continue;
            }
            if(n->left) levelq.push(n->left);
            if(n->right) levelq.push(n->right);
        }
    }
    return sum;
}

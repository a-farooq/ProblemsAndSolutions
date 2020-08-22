/****
Given a Binary Tree, your task is to print its level order traversal such that each level is separated by $.
For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

          1
       /     \
     2        3
   /    \     /   \
  4     5   6    7
    \
     8

Example 1:

Input:
          1
        /
       4
     /   \
    4     2
Output:1 $ 4 $ 4 2 $

Example 2:

Input:
            10
          /    \
        20      30
     /     \
    40     60
Output: 10 $ 20 30 $ 40 60 $
Your Task:
This is a function problem. You don't need to read input. Just complete the function levelOrder() that takes nodes as parameter and prints level order line-by-line. The newline for every test case is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of edges <= 1000
1 <= Data of a node <= 100
  ****/

/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//You are required to complete this method
void levelOrder(Node* node)
{
    if(!node) return;

    queue<Node*> levelq;
    levelq.push(node);
    levelq.push(nullptr);

    while(!levelq.empty())
    {
        Node* n = levelq.front();
        levelq.pop();

        if(n == nullptr) {
            cout << "$ ";
            if(levelq.empty())
                break;
            else levelq.push(nullptr);
        }
        else {
            cout << n->data << " ";
            if(n->left) levelq.push(n->left);
            if(n->right) levelq.push(n->right);
        }
    }
    //cout << endl;
}

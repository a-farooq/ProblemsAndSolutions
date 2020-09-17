/****
You are given a tree and you need to do the level order traversal on this tree.
Level order traversal of a tree is breadth-first traversal for the tree.



Level order traversal of above tree is 1 2 3 4 5

Example 1:

Input:
    1
  /   \
 3     2
Output:1 3 2

Example 2:

Input:
        10
     /      \
    20       30
  /   \
 40   60
Output:10 20 30 40 60 N N
Your Task:
You don't have to take any input. Just complete the function levelOrder() that takes the root node as parameter and returns an array containing the level order traversal of the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes<= 10ˆ4
1 <= Data of a node <= 10ˆ4


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
vector<int> levelOrder(Node* node)
{
    vector<int> res;

    if(!node) return res;

    queue<Node*> levelq;
    levelq.push(node);

	while(!levelq.empty())
    {
        int size = levelq.size();

        while(size--) {
            Node* node = levelq.front();
            levelq.pop();
            //cout << node->data << " ";
            res.push_back(node->data);

            if(node->left)
                levelq.push(node->left);
            if(node->right)
                levelq.push(node->right);
        }
    }
	/*
    levelq.push(nullptr);

    while(!levelq.empty())
    {
        Node* n = levelq.front();
        levelq.pop();

        if(n == nullptr) {
            if(levelq.empty()) break;
            else levelq.push(nullptr);
        }
        else {
            res.push_back(n->data);
            if(n->left) levelq.push(n->left);
            if(n->right) levelq.push(n->right);
        }
    }*/
    return res;
}

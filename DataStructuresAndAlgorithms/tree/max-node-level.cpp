/****
Given a Binary tree. Find the level in binary tree which has the maximum number of nodes.

Example 1:

Input:
      2
    /    \ 
   1      3
 /   \     \
4    6      8
     / 
    5
Output: 2
Explanation: The level 2 with nodes 4,
6 and 8 is the level with maximum
number of nodes. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function maxNodeLevel() that takes root node of the tree as input and returns an integer which is level of the tree with maximum nodes. The root is at level 0. If two or more levels have same number of maximum nodes , then return smallest level.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of level<=10
  ****/

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

int maxNodeLevelUtil1(Node* root)
{
    queue<Node*> que;
    que.push(root);
    que.push(nullptr);

    int cnt=0;
    int maxi=0;
    int levelres=0;
    int level=0;
    while(!que.empty()) {
        Node* node = que.front();

        que.pop();

        if(node==nullptr) {
            if(maxi < cnt) {
                maxi = cnt;
                levelres=level;
            }
            level++;

            if(que.empty()) break;
            que.push(nullptr);
            cnt=0;
        }
        else {
            cnt++;
            if(node->left) {
                que.push(node->left);
                //cnt++;
            }
            if(node->right) {
                que.push(node->right);
                //cnt++;
            }
        }

    }
    return levelres;
}

int maxNodeLevelUtil2(Node* root)
{
    queue<Node*> que;
    que.push(root);
    int level=0;
    int level_no=0;
    int maxi=0;

    while(1) {
        int nodeCount = que.size();

        if(nodeCount==0) break;

        if(maxi<nodeCount) {
            maxi = nodeCount;
            level_no = level;
        }

        while(nodeCount--) {
            Node* node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        level++;
    }
    return level_no;
}
// Return the level (0-indexed) with maximum number of nodes.
int maxNodeLevel(Node *root)
{
    //return maxNodeLevelUtil1(root);
    return maxNodeLevelUtil2(root);
}

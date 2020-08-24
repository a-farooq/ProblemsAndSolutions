/****
Given the binary Tree of and two-node values. Check whether the two-node values are cousins of each other or not.

Example 1:

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: 0

Example 2:

Input:
       1
     /   \ 
    2     3
   /       \
  5         4 
a = 5, b = 4
Output: 1
Explanation: Here, nodes 5 and 4 are
at the same level and have different
parent nodes. Hence, they both are cousins 

Your Task:
You don't need to read input or print anything. Your task is to complete the function isCousins() that takes the root node of the tree (having all nodes distinct), and two integers 'a' and 'b' as inputs. It returns true if the nodes with given values 'a' and 'b' are Cousins of each other and returns false otherwise. 
Two nodes value are cousins of each other if they are at the same level and have different parents. (The driver code will print 1 if the returned values is true,otherwise 0.)

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1<=Number of Nodes<=1000


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

struct CousinNode
{
    Node* parent;
    int level;
    CousinNode(Node* n, int lvl) : parent(n), level(lvl) {}
};
bool findNodes(Node* root, int a, int b, int level, CousinNode** n1, CousinNode** n2)
{
    if(!root) return false;

    if(root->left)
    if(root->left->data == a || root->left->data == b) {
        if(!(*n1)) { *n1 = new CousinNode(root, level); }
        else { *n2 = new CousinNode(root, level); }
    }

    if(root->right)
    if(root->right->data == a || root->right->data == b) {
        if(!(*n1)) { *n1 = new CousinNode(root, level); }
        else { *n2 = new CousinNode(root, level); }
    }

    if((*n1) && (*n2)) return true;

    if(findNodes(root->left, a, b, level+1, n1, n2)) return true;
    if(findNodes(root->right, a, b, level+1, n1, n2)) return true;

    return false;
}
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
bool isCousins(Node *root, int a, int b)
{
    if(!root) return false;
    /*
    CousinNode* cnode1 = nullptr;
    CousinNode* cnode2 = nullptr;
    findNodes(root, a, b, 1, &cnode1, &cnode2);

    if(cnode1->level == cnode2->level && cnode1->parent != cnode2->parent)
        return true;
    return false;*/

    queue<Node*> levelq;
    levelq.push(root);
    levelq.push(nullptr);
    pair<Node*, Node*> parents(nullptr, nullptr);
    pair<int, int> parentsLvl(0,0);
    int level = 1;

    while(!levelq.empty())
    {
        Node* n = levelq.front();
        levelq.pop();

        if(n == nullptr)
        {
            if(parents.first && parents.second) {
                if(parents.first != parents.second && parentsLvl.first == parentsLvl.second)
                    return true;
                else return false;
            }
            if(!levelq.empty()) { levelq.push(nullptr); level++; }
            else break;
        }
        else
        {
            if(n->left) {
                levelq.push(n->left);
                if(n->left->data == a || n->left->data == b) {
                    if(!parents.first) {
                        parents.first = n;
                        parentsLvl.first = level;
                    }
                    else {
                        parents.second = n;
                        parentsLvl.second = level;
                    }
                }
            }
            if(n->right) {
                levelq.push(n->right);
                if(n->right->data == a || n->right->data == b) {
                    if(!parents.first) {
                        parents.first = n;
                        parentsLvl.first = level;
                    }
                    else {
                        parents.second = n;
                        parentsLvl.second = level;
                    }
                }
            }
        }
    }
    return false;
}

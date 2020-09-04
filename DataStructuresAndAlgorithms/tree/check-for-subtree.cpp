/****
Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

Example:

S:          10
              /   \
            4     6
                 /
             30

T:                  26
                      /   \
                    10   3
                   /   \     \

               4       6     3
                       /
                    30

In above example S is subtree of T.

Please note that subtree has to be having same leaves non leaves.

   10
  /
20

For example, above tree is not subtree of

         10
       /     \
    20     50
   /   \
30   40

But a subtree of

         30
       /     \
    10     50
   /  
20  

Example 1:

Input:
T:      1          S:   3
      /   \            /
     2     3          4
   /  \    /
  N    N  4
Output: 1

Example 2:

Input:
T:      26         S:   26
       /   \           /  \
     10     N        10    N
   /    \           /  \
   20    30        20  30
  /  \            /  \
 40   60         40  60
Output: 1
Your Task:
Complete the function isSubtree() that takes two nodes as parameter and returns true or false.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 10^4
1 <= Value of nodes <= 10^4

  ****/

/* A binary tree node

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
bool isIdentical(Node* r1, Node* r2)
{
    if(!r1 && !r2) return true;

    if(!r1 || !r2) return false;

    bool ret = true;
    if(r1->data == r2->data) {
        ret = isIdentical(r1->left, r2->left);
        if(!ret) return false;
        ret = isIdentical(r1->right, r2->right);
    }
    else return false;

    return ret;
}
/*you are required to
complete this function */
bool isSubTree(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    if(!T || !S) return false;

    bool ret = isIdentical(T, S);
    if(ret) return ret;

    ret = isSubTree(T->left, S);
    if(ret) return ret;
    ret = isSubTree(T->right, S);
    return ret;
}

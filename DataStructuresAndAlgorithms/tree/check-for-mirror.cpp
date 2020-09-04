/****
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
MirrorTree1            

Example 1:

Input:
T1:     1     T2:     1
      /   \         /   \
     2     3       3     2
Output: 1
Example 2:

Input:
T1:     10      T2:   10
       /  \          /  \
      20  30        20  30
     /  \          /  \
    40   60       40  60
Output: 0

Your Task:
You don't need to take input. Just complete the function areMirror() that takes root node of two tree as parameter and returns true, if one is the mirror of other else returns false. (The driver's code print 1 if the returned value is true, otherwise 0)
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes<= 10000
-1000 <= Data of a node<= 1000

Same as check-for-symmetric but for single tree
  ****/

/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
bool mirrorUtil(Node* r1, Node* r2)
{
    if(!r1 && !r2) return true;

    if(!r1 || !r2) return false;

    bool ret = false;
    if(r1->data == r2->data) {
        ret = mirrorUtil(r1->left, r2->right);
        if(!ret) return false;

        ret = mirrorUtil(r1->right, r2->left);
    }
    return ret;
}
/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
    return mirrorUtil(a, b)?1:0;
}

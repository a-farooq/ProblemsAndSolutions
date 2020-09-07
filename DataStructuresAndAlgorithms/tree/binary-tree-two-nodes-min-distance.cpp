/****
Given a binary tree and two node values your task is to find the minimum distance between them.

Example 1:

Input:
        1
      /  \
     2    3
a = 2, b = 3
Output: 2
Explanation: The tree formed is:
       1
     /   \ 
    2     3
We need the distance between 2 and 3.
Being at node 2, we need to take two
steps ahead in order to reach node 3.
The path followed will be:
2 -> 1 -> 3. Hence, the result is 2. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findDist() which takes the root node of the Tree and the two node values as inputs and returns the minimum distance between the nodes represented by the two given node values.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10^4
1 <= Data of a node <= 10^5
  ****/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool findLCA(Node* root, int n, vector<int>&vec)
{
    if(!root) return false;

    if(root->data==n) {
        vec.push_back(root->data);
        return true;
    }

    //cout << root->data
    vec.push_back(root->data);

    bool ret = findLCA(root->left, n, vec);
    if(ret) return ret;

    ret = findLCA(root->right, n, vec);
    if(ret) return ret;

    vec.pop_back();
    return ret;
}

/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b)
{
    vector<int> vec1, vec2;
    //cout << root->data <<endl;
    bool ret1 = findLCA(root, a, vec1);
    //cout << root->data <<endl;
    bool ret2 = findLCA(root, b, vec2);

    if(!ret1 || !ret2) return 0;

    int d1 = vec1.size(); //distance of a from root
    int d2 = vec2.size(); //distance of b from root

    int d = 0; //distance of LCA from root
    for(; d<d1 && d<d2; d++) {
        if(vec1[d]!=vec2[d])
            break;
    }
    //cout << d1 << ", "<< d2 << ", "<<d <<endl;
    return d1+d2-2*d;
}

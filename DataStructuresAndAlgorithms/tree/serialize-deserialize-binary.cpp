/****
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Example 1:

Input:
      1
    /   \
   2     3
Output: 2 1 3
Example 2:

Input:
         10
       /    \
      20    30
    /   \
   40  60
Output: 40 20 60 10 30
Your Task:
The task is to complete two function serialize which takes the root node of the tree as input andstores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000


  ****/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/*this  function serializes
the binary tree and stores
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(!root) {
        A.push_back(-1);
        return;
    }
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

Node* deSerializeUtil(vector<int>&A, int& idx)
{
    Node* root = nullptr;
    if(A[idx]==-1 || idx>=A.size())
    {
        //idx++;
        return nullptr;
    }

    root = new Node(A[idx]);
    root->left = deSerializeUtil(A, ++idx);
    root->right = deSerializeUtil(A, ++idx);
    return root;
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
   //Your code here
   int idx=0;
   return deSerializeUtil(A, idx);
}

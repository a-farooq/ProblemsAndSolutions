//
//  main.cpp
//  Tree
//
//  Created by Aamil Farooq on 07/08/20.
//  Copyright © 2020 Aamil Farooq. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int a_data) : data(a_data)
    {
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    Node* root;
    
    Node* createNode(int data)
    {
        Node* newNode = new Node(data);
        return newNode;
    }
    
    void preorderUtil(Node* root, vector<int>&);
public:
    Tree(int data)
    {
        root = createNode(data);
    }

    Node* getRoot() { return root; }
    
    Node* insertLeft(Node* node, int data)
    {
        Node* newNode = createNode(data);
        node->left = newNode;
        return newNode;
    }
    
    Node* insertRight(Node* node, int data)
    {
        Node* newNode = createNode(data);
        node->right = newNode;
        return newNode;
    }
    
    vector<int> postOrder(Node*);
    
    vector<int> inOrder(Node* root);
    
    vector <int> preOrder(Node* root);
    
    int getSize(Node*);
    
    int height(Node* root);
};

/* Computes the number of nodes in a tree. */
int Tree::getSize(Node* node)
{
   // Your code here
   if(node == NULL) return 0;
   
   return getSize(node->left) + getSize(node->right) + 1;
}

/* Should return true if trees with roots as r1 and
   r2 are identical */
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 == NULL || r2 == NULL) return false;
        
    bool res = false;
    if(r1->data == r2->data)
        res = isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    Tree tree(1);
    Node* root = tree.getRoot();
    Node* n1 = tree.insertLeft(root, 5);
    Node* n2 = tree.insertLeft(n1, 10);
    Node* n3 = tree.insertRight(root, 39);
    
    cout << "Postorder traversal" << endl;
    vector<int> vec = tree.postOrder(root);
    for(auto node : vec)
        cout << node << " ";
    cout << endl;
    
    cout << "Inorder traversal" << endl;
    vec = tree.inOrder(root);
    for(auto node : vec)
        cout << node << " ";
    cout << endl;
    
    cout << "Preorder traversal" << endl;
    vec = tree.preOrder(root);
    for(auto node : vec)
        cout << node << " ";
    cout << endl;
    
    if(isIdentical(root, n1)) cout << "Identical" << endl;
    else cout << "Not Identical" << endl;
    
    cout << "Nodes count: " << tree.getSize(n1) << endl;
    
    cout << "Tree height: " << tree.height(root) << endl;
    
    return 0;
}

vector <int> Tree::postOrder(Node* root)
{
  // Your code here
    vector<int> vec;
    if(root == NULL) return vec;
    
    vec = postOrder(root->left);
    
    vector<int> tmp = postOrder(root->right);
    for(auto i : tmp)
        vec.push_back(i);
    
    vec.push_back(root->data);
    return vec;
}

// Return a vector containing the inorder traversal of the tree
vector<int> Tree::inOrder(Node* root)
{
  // Your code here
    vector<int> vec;
    if(root == NULL) return vec;
    
    vec = inOrder(root->left);
    vec.push_back(root->data);
    
    vector<int> tmp = inOrder(root->right);
    for(auto i : tmp)
        vec.push_back(i);
    
    return vec;
}

void Tree::preorderUtil(Node* root, vector<int> &vec)
{
  // Your code here
    if(!root) return;
    
    vec.push_back(root->data);
    preorderUtil(root->left, vec);
    preorderUtil(root->right, vec);
}

vector <int> Tree::preOrder(Node* root)
{
  // Your code here
    vector<int> vec;
    preorderUtil(root, vec);
    return vec;
}

// return the Height of the given Binary Tree
int Tree::height(Node* root)
{
   // Your code here
    if(!root) return 0;
    
    //if(!root->left && !root->right) return 1;
    
    return max(height(root->left), height(root->right)) + 1;
}

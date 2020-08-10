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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    Tree tree(1);
    Node* root = tree.getRoot();
    Node* n1 = tree.insertLeft(root, 5);
    Node* n2 = tree.insertLeft(n1, 10);
    Node* n3 = tree.insertRight(root, 39);
    
    vector<int> vec = tree.postOrder(root);
    for(auto node : vec) {
        cout << node << " ";
    }
    cout << endl;
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

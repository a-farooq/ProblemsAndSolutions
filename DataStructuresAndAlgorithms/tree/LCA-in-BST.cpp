

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
    if(!root) return NULL;

    //if(root->data >= n1 && root->data <= n2)
    //    return root;

    if(root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);
    else if(root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    return root;
}

/****

  ****/

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

/*  Function which returns the  root of
    the constructed binary tree. */

Node *createTree(int parent[], int n)
{
    if(n <= 0) return nullptr;

    Node* tree[n];
    for(int i = 0; i < n; i++)
        tree[i] = new Node(i);

    Node* root = nullptr;

    for(int i = 0; i < n; i++)
    {
        if(parent[i]==-1) root = tree[i];
        else {
            Node* par = tree[parent[i]];
            Node* child = tree[i];

            if(!par->left) par->left = child;
            else par->right = child;
        }
    }
    return root;

}

void inorder(Node* root)
{
	if(!root) return;

	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];

		Node* res = createTree(a, n);

		inorder(res);
		cout << endl;
	}
}

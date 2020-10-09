/****
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N input as arr[i].

Output:
Postorder traversal of the given preorder traversal is printed.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) [Function call stack size].

Constraints:
1 <= T <= 100
1 <= N <= 10^3
1 <= arr[i] <= 10^4

Example:
Input:
3
5
40 30 35 80 100
8
40 30 32 35 80 90 100 120

Output:
35 30 100 80 40
35 32 30 120 100 90 80 40

  ****/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

int find_right(int pre[], int start, int end, int root)
{
    for(int i=start; i<=end; i++)
    {
        if(pre[i]>root)
            return i;
    }
}

Node* createTree(int pre[], int start, int end)
{
    Node* root = nullptr;

    if(start<=end) {

        int rs_idx;// = find_right(pre, start, end, pre[start]);
        for(rs_idx=start; rs_idx<=end; rs_idx++)
        {
            if(pre[rs_idx]>pre[start])
                break;
        }

        root = new Node(pre[start]);

        //if(start==end) return root;

        //if(pre[start+1]<root->data) {
            root->left = createTree(pre, start+1, rs_idx-1);
        //}
        //else {
            root->right = createTree(pre, rs_idx, end);
        //}
    }
    return root;
}

void postorder(Node* root)
{
    if(!root)
        return;

    //cout << root->data << " ";

    postorder(root->left);

    //cout << root->data << " ";

    postorder(root->right);

    cout << root->data << " ";
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int pre[n];
	    for(int i=0; i<n; i++)
	        cin >> pre[i];

	    int idx = 0;
	    Node* root = createTree(pre, 0, n-1);

	    postorder(root);
	    cout << endl;
	}
	return 0;
}

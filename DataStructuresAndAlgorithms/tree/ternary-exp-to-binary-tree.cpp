/****
Given a string that contains ternary expressions. The expressions may be nested. You need to convert the given ternary expression to a binary Tree and return the root.

Input Format:
First line of input contains of test case T. The only line of test case consists of String s.

Outpu Format:
Preorder traversal of Tree formed

Your Task:
This is a function problem, you don't need to read input/output. Just complete the function convertExpression that take string and index(initialized from 0) as parameters.

Constraints:
1 <= T <= 100
1 <= |String| <= 100

Example:
Input:
2
a?b:c
a?b?c:d:e
Output:
a b c
a b c d e

Explanation:
Testcase1:
Input :  string expression =   a?b:c
Output : a
              /  \
             b    c
Testcase2:

Input : expression =  a?b?c:d:e
Output :   a
                /  \
              b    e
             /  \
            c    d
  ****/

Node* createTree(string st, int &i)
{
    Node* root = nullptr;
    if(i==st.length()) return nullptr;

    if(st[i]>='a'&&st[i]<='z') {
        root = new Node(st[i++]);
    }

    if(i < st.length() && st[i]=='?')
        root->left = createTree(st, ++i);

	//create right child only after left child
    if(i < st.length() && st[i]==':' && root->left) {
        root->right = createTree(st, ++i);
    }
    return root;
}
Node *convertExpression(string str,int i)
{
    return createTree(str, i);
}

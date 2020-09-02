/****
Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

Note: The flattened list will be printed using the bottom pointer instead of next pointer.

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.
Your Task:
You need to complete the function flatten() that takes head of the list as parameter and returns the root of flattened list. The printing is done by the driver code.

Note: Try to solve the problem without using any extra space.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 10^3
  ****/

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

Node* mergeList(Node* p1, Node* p2)
{
    //cout << "newhead: ";
    Node* newhead = nullptr;
    if(p1->data < p2->data) {
        newhead = p1;
        p1 = p1->bottom;
    }
    else {
        newhead = p2;
        p2 = p2->bottom;
    }
    //print(newhead);

    Node* p = newhead;

    while(p1 && p2) {
        if(p1->data < p2->data) {
            p->bottom = p1;
            p1 = p1->bottom;
        }
        else {
            p->bottom = p2;
            p2 = p2->bottom;
        }
        p = p->bottom;
        //print(newhead);
    }
    while(p1) {
        p->bottom = p1;
        p1 = p1->bottom;
        p = p->bottom;
    }
    while(p2) {
        p->bottom = p2;
        p2 = p2->bottom;
        p = p->bottom;
    }

    //print(newhead);
    //cout << endl;
    return newhead;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(!root || !root->next) return root;

    Node* p = root->next;
    while(p) {
        root = mergeList(root, p);
        p = p->next;
    }
    return root;
}

/****
Given two linked lists, your task is to complete the function makeUnion(), that returns the union of two linked lists. This union should include all the distinct elements only.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 1 2 3 4 6 8 9
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Note: The new list formed should be in non-decreasing order.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1<size of the linked lists<=5000
  ****/

/*
// structure of the node is as follows

struct node
{
	int data;
	struct node* next;

	node(int x){
	    data = x;
	    next = NULL;
	}

};

*/

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    if(!head1) return head2;
    if(!head2) return head1;

    set<int> hashset;
    while(head1) {
        hashset.insert(head1->data);
        head1 = head1->next;
    }
    while(head2) {
        hashset.insert(head2->data);
        head2 = head2->next;
    }

    Node* reshead = nullptr;
    Node* restail = nullptr;
    for(auto val : hashset) {
        if(!reshead) reshead = restail = new Node(val);
        else {
            restail->next = new Node(val);
            restail = restail->next;
        }
    }
    return reshead;
}

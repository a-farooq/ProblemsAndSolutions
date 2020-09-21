/****
Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

Example 1:

Input:
N = 8
value[] = {7,3,5,2,6,4,1,8}
Output:
1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1
Explanation: After sorting the given
linked list in both ways, resultant
matrix will be as given in the first
two line of output, where first line
is the output for non-decreasing
order and next line is for non-
increasing order.
Example 2:

Input:
N = 5
value[] = {9,15,0,-1,0}
Output:
-1 0 0 9 15
15 9 0 0 -1
Explanation: After sorting the given
linked list in both ways, the
resultant list will be -1 0 0 9 15
in non-decreasing order and 
15 9 0 0 -1 in non-increasing order.
Your Task:
The task is to complete the function sortDoubly() which sorts the doubly linked list. The printing is done automatically by the driver code.

Constraints:
1 <= N <= 10^5

Solution:
Same as merge sort of single list with addition of setting prev pointers
  ****/

/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */

Node* findmid(Node* head)
{
    Node* p1 = head;
    Node* p2 = head->next;

    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

Node* merge(Node* p1, Node* p2)
{
    if(!p1) return p2;
    if(!p2) return p1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while(p1 && p2) {
        if(p1->data < p2->data) {
            if(!head) head = tail = p1;
            else {
                tail->next = p1;
                p1->prev = tail;
                tail = tail->next;
            }
            p1 = p1->next;
        }
        else {
            if(!head) head = tail = p2;
            else {
                tail->next = p2;
                p2->prev = tail;
                tail = tail->next;
            }
            p2 = p2->next;
        }
    }
    if(p1) {
        tail->next = p1;
        p1->prev = tail;
    }
    else if(p2) {
        tail->next = p2;
        p2->prev = tail;
    }

    return head;
}
// Function to merge two DLLs
struct Node *sortDoubly(struct Node *head)
{
	// Your code here
	if(!head || !head->next) return head;

	Node* mid = findmid(head);
	Node* midnext = nullptr;
	if(mid) {
    	midnext = mid->next;
    	midnext->prev = nullptr;
    	mid->next = nullptr;
	}

	Node* p1 = sortDoubly(head);
	Node* p2 = sortDoubly(midnext);

	return merge(p1, p2);
}

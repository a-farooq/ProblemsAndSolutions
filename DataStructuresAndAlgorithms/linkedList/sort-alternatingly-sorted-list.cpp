/****
Given a Linked list of size N, the list is in alternating ascending and descending orders. Your task is to complete the function sort() that sorts the given linked list in non-decreasing order.

Input:
The function takes a single argument as input the reference pointer to the head of the linked list.
There are T test cases and for each test case the function will be called separately.

Output:
For each test case function should return reference pointer to the head of the new linked list.

User Task:
The task is to complete the function sort() which should sort the linked list in non-decreasing order

Note: Complete the task in constanst auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= A[] <= 10^3

Example:
Input:
2
6
1 9 2 8 3 7
5
13 99 21 80 50

Output:
1 2 3 7 8 9
13 21 50 80 99

Explanation:
Testcase 1: After sorting the given linked list, the list will be as 1-> 2-> 3-> 7-> 8-> 9.

Solution:
1. Split the list into two. One should contain the even indexed numbers (which are in increasing order). Second list will contain the numbers which were odd indexed in the original list (these are sorted in decreasing order).
2. Reverse the list with decreasing numbers.
    Now merge the two lists.
  ****/

/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;

	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

Node* reverse(Node* head)
{
    Node* p1 = nullptr;
    Node* p2 = head;
    Node* p3 = nullptr;

    while(p2) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    return p1;
}

Node* merge(Node* h1, Node* h2)
{
    if(!h1) return h2;
    if(!h2) return h1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while(h1 && h2) {
        if(h1->data < h2->data) {
            if(!tail) head = tail = h1;
            else {
                tail->next = h1;
                tail = h1;
            }
            h1 = h1->next;
        }
        else {
            if(!tail) head = tail = h2;
            else {
                tail->next = h2;
                tail = h2;
            }
            h2 = h2->next;
        }
    }
    if(h1)
        tail->next = h1;

    if(h2)
        tail->next = h2;

    return head;
}
// your task is to complete this function
void sort(Node **head)
{
    Node* evenIdxHead = nullptr;
    Node* evenIdxTail = nullptr;
    Node* oddIdxHead = nullptr;
    Node* oddIdxTail = nullptr;

    Node* p1 = *head;
    bool even = true;
    while(p1) {
        if(even) {
            if(!evenIdxTail) evenIdxHead = evenIdxTail = p1;
            else {
                evenIdxTail->next = p1;
                evenIdxTail = p1;
            }
        }
        else {
            if(!oddIdxTail) oddIdxHead = oddIdxTail = p1;
            else {
                oddIdxTail->next = p1;
                oddIdxTail = p1;
            }
        }
        even = !even;
        p1 = p1->next;
    }
    if(oddIdxTail) {
        oddIdxTail->next = nullptr;
    }
    oddIdxHead = reverse(oddIdxHead);
    if(evenIdxTail) {
        evenIdxTail->next = nullptr;
    }

    *head = merge(evenIdxHead, oddIdxHead);
}

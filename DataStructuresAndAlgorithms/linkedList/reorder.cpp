/****
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.

Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Example 2:

Input:
LinkedList: 1->7->3->4
Output: 1 4 7 3.
Your Task:
The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 10^4
  ****/

/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

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

void reorderList(Node* head)
{
    if(!head || !head->next || !head->next->next)
        return;

    Node* mid = findmid(head);
    Node* p1 = head;
    Node* p2 = mid->next;
    mid->next = nullptr;

    p2 = reverse(p2);
    Node* h = p1;
    Node* t = p1;
    p1 = p1->next;

    bool first = false;
    while(p1 || p2) {
        if(first) {
            t->next = p1;
            t = t->next;
            p1 = p1->next;
        }
        else {
            t->next = p2;
            t = t->next;
            p2 = p2->next;
        }
        first = !first;
    }
    //return h;
}

/****
Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.

Example 1:

Input:
LinkedList: 1->2->3->4
Output: 1 3 2 4
Example 2:

Input:
LinkedList: 1->2->3->4->5
Output: 1 3 5 2 4
Your Task:
The task is to complete the function rearrangeEvenOdd() which rearranges the nodes in the linked list as required and return the head of the linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Size of the linked list <= 10000
1 <= values of linked list<= 1000


  ****/

/* Node structure

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

// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head)
{
    //evenhead for even index i.e. 0,2,...
    //oddhead for odd index i.e. 1,3,...
    Node* evenhead = nullptr;
    Node* eventail = nullptr;
    Node* oddhead = nullptr;
    Node* oddtail = nullptr;

    if(head) {
        evenhead = eventail = head;
        head = head->next;
    }
    if(head) {
        oddhead = oddtail = head;
        head = head->next;
    }
    bool even = true;
    while(head)
    {
        if(even) {
            eventail->next = head;
            eventail = head;
        }
        else {
            oddtail->next = head;
            oddtail = head;
        }
        even = !even;
        head = head->next;
    }
    if(oddtail) {
        oddtail->next = nullptr;
        if(eventail) {
            eventail->next = oddhead;
        }
        else evenhead = oddhead;
    }
    else if(eventail) eventail->next = nullptr;

    return evenhead;
}

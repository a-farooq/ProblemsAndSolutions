/****
Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4
Example 2:

Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9
Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linkedlist.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 200
  ****/

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 */

// This function should return head of
// the modified list
Node *sortedInsert(Node* head, int x)
{
    Node* node = new Node(x);

    if(!head) return node;


    if(head->data > x) {
        Node* tail = head;
        while(tail->next != head) tail = tail->next;

        tail->next = node;
        node->next = head;
        head = node;
    }
    else {
        Node* p1 = head;
        while(p1->next->data < x) {
            p1 = p1->next;
        }
        node->next = p1->next;
        p1->next = node;
    }
    return head;
}

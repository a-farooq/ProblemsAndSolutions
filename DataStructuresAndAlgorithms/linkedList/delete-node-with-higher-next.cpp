/****
Given a singly linked list, remove all the nodes which have a greater value on its next adjacent element.

Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on their next node. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
Your Task:
The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of linked list <= 1000
1 <= element of linked list <= 1000
Note: Try to solve the problem without using any extra space.

Solution:
1. Reverse list
2. Remove nodes which have bigger value on the left.

To do this, simply iterate from left to right, and store the max value seen. Keep comparing all nodes to the stored max value.

In the end reverse the list again.
  ****/

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
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
Node *compute(Node *head)
{
    if(!head || !head->next) return head;
    
    head = reverse(head);
    
    int maxi = head->data;
    Node* h = head;
    Node *t = head;
    head = head->next;
    while(head) {
        Node* tmp = nullptr;
        if(head->data >= maxi) {
            maxi = head->data;
            t->next = head;
            t = t->next;
        }
        else {
            tmp = head;
        }
        head = head->next;
        if(tmp) delete tmp;
    }
    if(t) t->next = nullptr;
    h = reverse(h);
    return h;
}

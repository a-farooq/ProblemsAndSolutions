/****
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^1000
  ****/

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

Node* reverse(Node* head)
{
    if(!head || !head->next) return head;

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

Node* addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    head = reverse(head);

    Node* p1 = head;
    Node* prev = p1;
    int carry = 1;
    while(p1) {
        p1->data += carry;
        if(p1->data < 10) {
            return reverse(head);
            //carry = 0;
            //break;
        }

        p1->data = 0;
        prev = p1;
        p1 = p1->next;
    }
    if(carry) {
        prev->next = new Node(1);
    }
    return reverse(head);
}

/****
Given a sorted singly linked list and a data, your task is to insert the data in the linked list in a sorted way i.e. order of the list doesn't change.

Example 1:

Input:
LinkedList: 25->36->47->58->69->80
data: 19
Output: 19 25 36 47 58 69 80
Example 2:

Input:
LinkedList: 50->100
data: 75
Output: 50 75 100
Your Task:
The task is to complete the function sortedInsert() which should insert the element in sorted Linked List and return the head of the linked list

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^4
-99999 <= A[i] <= 99999, for each valid i


  ****/

/*
structure of the node of the list is as
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

// Should return head of the modified linked list
Node *sortedInsert(struct Node* head, int data)
{
    Node* newnode = new Node(data);

    if(!head) return newnode;

    //insert at start
    if(head->data > data) {
        newnode->next = head;
        return newnode;
    }

    Node* p1 = head;
    Node* p2 = p1->next;
    while(p2) {
        if(p2->data > data) {
            //insert in between
            p1->next = newnode;
            newnode->next = p2;
            //p1 = p2;
            //p2 = p2->next;
            return head;
        }
        //else {
            p1 = p1->next;
            p2 = p2->next;
        //}
    }
    //insert at end
    p1->next = newnode;
    return head;
}

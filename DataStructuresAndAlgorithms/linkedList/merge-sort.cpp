/****
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 10^5
  ****/

/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node* findmid(Node* head)
{
    if(!head || !head->next) return head;

    Node* p1 = head;
    Node* p2 = head->next;

    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

void print(Node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* mergeList(Node* p1, Node* p2)
{
    //cout << "newhead: ";
    Node* newhead = nullptr;
    if(p1->data < p2->data) {
        newhead = p1;
        p1 = p1->next;
    }
    else {
        newhead = p2;
        p2 = p2->next;
    }
    //print(newhead);

    Node* p = newhead;

    while(p1 && p2) {
        if(p1->data < p2->data) {
            p->next = p1;
            p1 = p1->next;
        }
        else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
        //print(newhead);
    }
    while(p1) {
        p->next = p1;
        p1 = p1->next;
        p = p->next;
    }
    while(p2) {
        p->next = p2;
        p2 = p2->next;
        p = p->next;
    }

    //print(newhead);
    //cout << endl;
    return newhead;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head)
{
    if(!head || head->next == nullptr) return head;

    //cout << "full list: ";
    //print(head);

    Node* mid = findmid(head);
    Node* midnext = nullptr;
    if(mid) {
        midnext = mid->next;
        mid->next = nullptr;
    }
    //cout << "first half: ";
    //print(head);
    //cout << "second half: ";
    //print(midnext);
    //cout << endl;

    Node* p1 = mergeSort(head);
    //cout << "p1: ";
    //print(p1);
    //cout << endl;
    Node* p2 = mergeSort(midnext);
    //cout << "p2: ";
    //print(p2);
    //cout << endl;

    return mergeList(p1, p2);
}

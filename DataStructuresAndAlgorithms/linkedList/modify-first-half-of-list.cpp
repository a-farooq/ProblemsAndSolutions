/****
Given a singly linked list containing N nodes. Modify the value of first half nodes such that 1st node’s new value is equal to the last node’s value minus first node’s current value, 2nd node’s new value is equal to the second last node’s value minus 2nd node’s current value, likewise for first half nodes. If n is odd then the value of the middle node remains unchanged.
Note: Input in the linked list is like new node will be entered at the head position (1st position).

Input:
First line consists of T test cases. First line of every test case consists of N, denoting the number of nodes. Second line of every test case consists of Node of linked list.

Output:
Single line output, return the head of modified linked list.

User Task:
The task is to complete the function modifyTheList() which should modify the list as required.

Constraints:
1 <= T <= 200
1 <= N <= 100

Example:
Input:
2
5
6 3 5 4 10
6
10 7 12 8 9 2

Output:
-4 -1 5 4 10
8 -2 4 8 9 2

Explanation:
Testcase 1: After modifying the linked list as required, we have new linked list containing the elements as -4, -1, 5, 4, 10.

  ****/

/*Complete the function below
Node is as follows:
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
    Node* p2 = head;

    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}
struct Node* modifyTheList(struct Node *head)
{
    if(!head) return nullptr;

    Node* mid = findmid(head);
    Node* p2 = mid;

    stack<Node*> stk;
    while(p2) {
        stk.push(p2);
        p2 = p2->next;
    }

    Node* p1=head;
    while(!stk.empty() && p1!=mid) {
        Node* top = stk.top();
        p1->data -= top->data;
        p1 = p1->next;
        stk.pop();
    }
    return head;
}

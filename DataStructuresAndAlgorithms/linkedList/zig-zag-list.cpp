/****
Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

Example 1:

Input:
LinkedList: 1->2->3->4 
Output: 1 3 2 4
Example 2:

Input:
LinkedList: 11->15->20->5->10
Output: 11 20 5 15 10
Explanation: In the given linked list,
after arranging them as 11 < 20 > 5
< 15 > 10 in the pattern as asked above.
Your Task:
The task is to complete the function zigZag() which should reorder the list as required and return the head of the linked list.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of linked list(a) <= 1000


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


Node *zigZag(Node* head)
{
    bool flag=true;
    Node* p1 = head;

    while(p1 && p1->next) {
        if(flag) {
            if(p1->data > p1->next->data)
                swap(p1->data, p1->next->data);
        }
        else {
            if(p1->data < p1->next->data)
                swap(p1->data, p1->next->data);
        }
        flag = !flag;
        p1 = p1->next;
    }
    return head;
}

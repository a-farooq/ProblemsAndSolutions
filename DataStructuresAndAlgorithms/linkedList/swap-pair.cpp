/*****

Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the linked list and the next line contains linked list data.

Output:
Output the linked list after swapping pairwise nodes.

User Task:
The task is to complete the function pairWiseSwap() which takes the head node as the only argument and returns the modified head.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 103

Example:
Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7

Explanation:
Testcase 1: After swapping each pair considering (1,2), (2, 4), (5, 6).. so on as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as a new linked list.
******/

/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

//first approach - swapping data
Node* pairWiseSwap(struct Node* head) {
    Node* p1 = head;
    while(p1 && p1->next) {
        swap(p1->data, p1->next->data);
        p1 = p1->next->next;
    }
    
    return head;
}

//second approach - swapping links
Node* pairWiseSwap2(struct Node* head) {
    // The task is to complete this method
    if(!head || !head->next) return head;
    
    Node* p1 = NULL;
    Node* p2 = head;
    Node* p3 = p2->next;
    Node* p4 = p3->next;
    
    while(1)
    {
        p2->next = p3->next;
        p3->next = p2;
        if(p1) p1->next = p3;
        else head = p3;
        p1 = p2;
        p2 = p4;
        if(!p2 || !p2->next) break;
        p3 = p4->next;
        p4 = p4->next->next;
    }
    
    return head;
}

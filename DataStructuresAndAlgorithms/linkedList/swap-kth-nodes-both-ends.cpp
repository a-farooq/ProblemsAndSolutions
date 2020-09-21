/****
Given a singly linked list of size N, and an integer K. You need to swap the Kth node from beginning and Kth node from the end in the linked list.
Note: You need to swap the nodes through the links and not changing the content of the nodes.

Example 1:

Input:
N = 4,  K = 1
value[] = {1,2,3,4}
Output: 1
Explanation: Here K = 1, hence after
swapping the 1st node from the beginning
and end thenew list will be 4 2 3 1.
Example 2:

Input:
N = 5,  K = 3
value[] = {1,2,3,4,5}
Output: 1
Explanation: Here k = 3, hence after
swapping the 3rd node from the beginning
and end the new list will be 1 2 3 4 5.
Your Task: 
The task is to complete the function swapkthnode(), which has arguments head, num(no of nodes), and K, and it should return a new head. The validation is done internally by the driver code to ensure that the swapping is done by changing references/pointers only.  A correct code would always cause output as 1.

Expected Time Complexity: O(n)
Expected Auxillary space Complexity: O(1)

Constraints:
1 <= N <= 10^3
1 <= K <= 10^3

Solution:
1. Simply find both K nodes from front and end and swap them using temp node.
2. Consider the following testcases:

Let X be the kth node from beginning and Y be the kth node from end. Following are the interesting cases that must be handled.
1) Y is next to X
2) X is next to Y
3) X and Y are same
4) X and Y don’t exist (k is more than number of nodes in linked list)
  ****/

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int K)
{
    // Your Code here
    if(!head || !head->next || K>num) return head;

    //K is same from both ends
    if(2*K-1==num) return head;

    Node* p1 = head;
    Node* pp1 = nullptr;
    Node* pp2 = nullptr;

    Node* tmp = head;
    int c=1;
    while(c++ < K) {
        pp1 = p1;
        p1 = p1->next;
        //tmp = tmp->next;
    }
    Node* p2 = head;
    //tmp = p1->next;
    c=1;
    while(c++ < num-K+1) {
        pp2 = p2;
        p2 = p2->next;
        //tmp = tmp->next;
    }

    if(pp1)
        pp1->next = p2;

    if(pp2)
        pp2->next = p1;

    tmp = p1->next;
    p1->next = p2->next;
    p2->next = tmp;

    if(K==1) head = p2;
    else if(K==num) head = p1;

    return head;
}


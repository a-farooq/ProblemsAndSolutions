/****
Given a linked list, you have to perform the following task:

Extract the alternative nodes from starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
​Example 1:

Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 10 9 3 9 4 5 1 4
Explanation: Reversing the alternative
nodes from the given list, and then
appending them to the end of the list
results in a list with the elements as
10 9 3 9 4 5 1 4.
​Example 2:

Input:
LinkedList = 1->2->3->4->5
Output: 1 3 5 4 2 
Explanation:
Your Task:
The task is to complete the function rearrange() which should rearrange the list as required.

Note: Try to solve the problem without using any extra memory.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 50
1 <= Node_value <= 1000


  ****/

/*
  reverse alternate nodes and append at the end
  The input list will have at least one element
  Node is defined as
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

void rearrange(struct Node *head)
{
    if(!head || !head->next) return;

    Node* ohead = head;
    Node* otail = head;
    Node* ehead = head->next;
    Node* etail = head->next;

    Node* tmp = etail->next;
    bool even = false;
    while(tmp) {
        if(even) {
            etail->next = tmp;
            etail = etail->next;
        }
        else {
            otail->next = tmp;
            otail = otail->next;
        }
        tmp = tmp->next;
        even = !even;
    }
    if(etail) etail->next = nullptr;
    if(otail) otail->next = nullptr;

    ehead = reverse(ehead);
    otail->next = ehead;

}



/***********


Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains N and M, and next two line contains N and M sorted elements in two lines for each.

Output:
For each testcase, print the merged list in sorted form.

User Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= T <= 100
1 <= N, M <= 104
1 <= Node's data <= 105

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 
Output:
2 3 5 10 15 20 40
1 1 2 4

Explanation:
Testcase 1: After merging the two linked lists, we have merged list as 2, 3, 5, 10, 15, 20, 40.
Testcase 2: After merging the given two linked list , we have 1, 1, 2, 4 as output.
********/

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node* head, *temp;
    if(head_A == NULL) return head_B;
    if(head_B == NULL) return head_A;
    
    if(head_A->data <= head_B->data) {
        head = head_A;
        head_A = head_A->next;
    }
    else {
        head = head_B;
        head_B = head_B->next;
    }
    
    // code here
    temp = head;
    //cout << "***" << temp->data << endl;
    while(head_A != NULL && head_B != NULL)
    {
        if(head_A->data < head_B->data)
        {
            temp->next = head_A;
            head_A = head_A->next;
        }
        else {
            temp->next = head_B;
            head_B = head_B->next;
        }
        
        //cout << "***" << temp->data << endl;
        temp = temp->next;
    }
    if(head_A) temp->next = head_A;
    else if(head_B) temp->next = head_B;
    
    return head;
}

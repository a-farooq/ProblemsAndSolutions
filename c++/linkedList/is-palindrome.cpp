/*******
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list N and next line contains N integers as data of linked list.

Output:
For each test case output will be 1 if the linked list is a palindrome else 0.

User Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)
Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

Constraints:
1 <= T <= 103
1 <= N <= 50

Example:
Input:
2
3
1 2 1
4
1 2 3 4
Output:
1
0

Explanation:
Testcase 1: The given linked list is 1 2 1 , which is a pallindrome and Hence, the output is 1.
Testcase 2: The given linked list is 1 2 3 4 , which is not a pallindrome and Hence, the output is 0.
******/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

struct Node* reverseList(struct Node *head)
{
    if(!head) return head;
    
    Node* p1 = NULL;
    Node* p2 = head;
    Node* p3 = NULL;
    
    while(p2) 
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    return p1;
}

Node* getMiddle(Node* head)
{
    if(!head) return head;
    
    Node* p1 = head;
    
    while(p1 && p1->next)
    {
        head = head->next;
        p1 = p1->next->next;
    }
    
    return head;
}

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    if(!head) return false;
    
    Node* mid = getMiddle(head);
    Node* p1 = head;
    Node* p2 = reverseList(mid);
    //Node* p3 = p2;
    
    while(p1 && p2)
    {
        if(p1 == p2) return true;
        
        if(p1->next == p2 && p1->data == p2->data) return true;
        
        if(p1->data != p2->data) return false;
        
        p1 = p1->next;
        p2 = p2->next;
    }
    
    //p3 = reverseList(p2);
    return false;
}


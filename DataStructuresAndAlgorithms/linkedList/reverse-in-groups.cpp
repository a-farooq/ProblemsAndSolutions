/********
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

User Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Example:
Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4

Explanation:
Testcase 1: Since, k = 4. So, we have to reverse every group of four elements. Modified linked list is as 4, 2, 2, 1, 8, 7, 6, 5.
*******/

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
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
void print(node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reversek(struct node* head, struct node** newhead, struct node** newtail)
{
    //cout << "inside reversek: ";
    
    node* p1 = NULL;
    node* p2 = head;
    node* p3 = NULL;
    
    //print(head);
    
    while(p2) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    
    //print(p1);
    //print(newhead);
    
    *newtail = head;
    *newhead = p1;
    
    //cout << newhead << endl;
    //cout << "leaving reversek" << endl;
}

struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    node* newhead = NULL;
    node* newtail = NULL;
    node* oldtail = NULL;
    node* reshead = NULL;
    node* prevtail = NULL;
    
    while(head) {
        
        node* p1 = NULL;
        node* p2 = head;
        node* p3 = NULL;
        int count = 0;
        
        while(p2 && count < k) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            count++;
        }

        if(prevtail) prevtail->next = p1;
        else newhead = p1;
        
        prevtail = head;
        
        head->next = NULL;
        head = p2;
    }
    return newhead;
}

struct node *reverse2 (struct node *head, int k)
{ 
    // Complete this method
    node* newhead = NULL;
    node* newtail = NULL;
    node* oldtail = NULL;
    node* reshead = NULL;
    
    while(head) {
        int k2 = k;
        node* p1 = head;
        node* p2 = head->next;
        while(k2 > 1 && p1 && p2) {
            
            p1 = p1->next;
            p2 = p2->next;
            k2--;
        }
        
        if(p1) p1->next = NULL;
        
        //print(head);
        reversek(head, &newhead, &newtail);
        //cout << "reversed: ";
        //cout << newhead << "--";
        //print(newhead);
        
        head = p2;
        
        if(oldtail) oldtail->next = newhead;
        else reshead = newhead;
        
        oldtail = newtail;
    }
    
    return reshead;
}

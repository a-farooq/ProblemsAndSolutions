/****
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in decreasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.

Output:
For each testcase, print the merged linked list which is in non-increasing order.

User Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Constraints:
1 <=T<= 50
1 <= N, M <= 1000

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
40 20 15 10 5 3 2
4 2 1 1

Explanation:
Testcase 1: After merging the two lists in decreasing order, we have new lists as 40->20->15->10->5->3->2.
  ****/

/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
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

struct Node * mergeResult(Node *h1, Node *h2)
{
    if(!h1 && !h2) return nullptr;
    
    if(!h1) return reverse(h2);
    
    if(!h2) return reverse(h1);
    
    Node* head;
    Node* h;
    
    if(h1->data < h2->data) {
        h = h1;
        h1 = h1->next;
    }
    else {
        h = h2;
        h2 = h2->next;
    }
    head = h;
    while(h1 && h2) {
        if(h1->data < h2->data) {
            h->next = h1;
            h = h1;
            h1 = h1->next;
        }
        else {
            h->next = h2;
            h = h2;
            h2 = h2->next;
        }
        /*
        Node* tmp = head;
        while(tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;*/
    }
    while(h1) {
        h->next = h1;
        h = h->next;
        h1 = h1->next;
    }
    /*
    Node* tmp = head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;*/
    
    while(h2) {
        h->next = h2;
        h = h->next;
        h2 = h2->next;
    }
    /*
    tmp = head;
    while(tmp) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;*/
    
    //h->next = nullptr;
    
    return reverse(head);
}

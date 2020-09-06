/****
Given a linked list L of N nodes, sorted in ascending order based on the absolute values of its data. Sort the linked list according to the actual values.
Ex: Input : 1 -> -2 -> -3 -> 4 -> -5 
      Output: -5 -> -3 -> -2 -> 1 -> 4

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case contains a positive integer N denoting the size of linked list. The second line of each test case contains N space separated integers denoting the values of N nodes.


Output
Corresponding to each test case, the expected output will be space separated values of the sorted linked list.


Constraints
1 <= T <= 100
0 <   N  <= 30
-100 <= L[i] <= 100

Examples 

Input
2
3
1 -3 -4
4
0 -2 3 -10


Output
-4  -3  1
-10 -2  0  3

Solution:
1. segregate positive and negative numbers in two list
2. positive list will be sorted in non-decreasing and negative list will be sorted in decreasing
3. reverse negative list and put before positive list
  ****/

/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

Node* reverse(Node* head)
{
    if(!head || !head->next) return head;

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

void print(Node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/*Your method shouldn't print anything
 it should transform the passed linked list */
void sortList(Node** head)
{
    Node* p = *head;

    Node* poshead = nullptr;
    Node* postail = nullptr;
    Node* neghead = nullptr;
    Node* negtail = nullptr;

    while(p) {
        if(p->data >= 0) {
            if(!postail) poshead = postail = p;
            else {
                postail->next = p;
                postail = p;
            }
        }
        else {
            if(!negtail) neghead = negtail = p;
            else {
                negtail->next = p;
                negtail = p;
            }
        }
        p = p->next;
    }
    if(negtail) negtail->next = nullptr;
    if(postail) postail->next = nullptr;

    negtail = neghead;
    neghead = reverse(neghead);

    if(postail) {
        postail->next = nullptr;
        if(negtail)
            negtail->next = poshead;
        else neghead = poshead;
    }
    else if(negtail) negtail->next = nullptr;

    *head = neghead;
}

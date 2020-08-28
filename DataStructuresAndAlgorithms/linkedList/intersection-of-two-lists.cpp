/****
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Input:
First line of input contains number of test cases T. Then T test cases follow.
In each test case, first line contains the number n, i.e. number of nodes in list 1 and second lines contains the n space separated values of the nodes.
Similarly, third line contains m, i.e. number of nodes in list 2 and fourth line of test case contains the data of m nodes of list 2.

Output:
The intersection list will be printed in a new line for each test case.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

User Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.

Constraints:
1 <= T <= 1000
1 <= n,m <= 10^3

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)

Example:
Input:
1
6
9 6 4 2 3 8
4
1 2 8 6
Output:
6 2 8
  ****/

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // code here
    // return the head of intersection list
    if(!head1 || !head2) return nullptr;

    unordered_set<int> hashset;
    Node* reshead = nullptr;
    Node* resiter = reshead;
    while(head2)
    {
        hashset.insert(head2->data);
        head2 = head2->next;
    }

    while(head1)
    {
        auto setiter = hashset.find(head1->data);
        if(setiter != hashset.end()) {
            if(!reshead) {
                reshead = resiter = head1;
                //resiter = head1;
            }
            else {
                resiter->next = head1;
                resiter = resiter->next;
            }
        }
        head1 = head1->next;
    }
    resiter->next = nullptr;
    return reshead;
}

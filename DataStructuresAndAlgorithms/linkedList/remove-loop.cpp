/****
You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 

Note: C is the position of the node to which the last node is connected. If it is 0 then no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
C = 2
Output: 1
Explanation: In the first test case
N = 3.The linked list with nodes
N = 3 is given. Here, x = 2 which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop. 

Example 2:
Input:
N = 4
value[] = {1,8,3,4}
C = 0
Output: 1
Explanation: N = 4 and x = 0, which
means lastNode->next = NULL, thus
the Linked list does not contains
any loop.
Your Task:
Your task is to complete the function removeLoop(). The only argument of the function is head pointer of the linked list. Simply remove the loop in the list (if present) without disconnecting any nodes from the list. The driver code will print 1 if your code is correct.

Expected time complexity : O(n)

Expected auxiliary space : O(1)

Constraints:
1 <= N <= 10^4


  ****/

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

int countNodesInLoop(struct Node *head)
{
    if(!head || !head->next) return 0;
    if(head->next == head) return 1;

    Node* p1 = head;
    Node* p2 = head->next;

    bool loop = false;
    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1 == p2) { loop = true; break; }
    }

    if(!loop) return 0;

    int count = 1;
    p2 = p2->next;
    while(p1!=p2) {
        p2 = p2->next;
        count++;
    }
    return count;

}

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    int size = countNodesInLoop(head);

    if(!size) return;

    //cout << "size: " << size << endl;

    Node* p1 = head;
    Node* p2 = p1;
    Node* prev = p2;
    while(size--) {
        prev = p2;
        p2 = p2->next;
    }

    while(p1 != p2) {
        p1 = p1->next;
        prev = p2;
        p2 = p2->next;
    }
    prev->next = nullptr;
}

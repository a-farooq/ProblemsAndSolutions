/****
You are given a Singly Linked List with N nodes where each node next pointing to its next node. You are also given M random pointers , where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

ArbitLinked List1

Example 1:

Input:
N = 4, M = 
value = {1,2,3,4}
pairs = {{1,2},{2,4}}
Output: 1
Explanation: In this test case, there
re 4 nodes in linked list.  Among these
4 nodes,  2 nodes have arbit pointer
set, rest two nodes have arbit pointer
as NULL. Third line tells us the value
of four nodes. The fourth line gives the
information about arbitrary pointers.
The first node arbit pointer is set to
node 2.  The second node arbit pointer
is set to node 4.
Example 2:

Input:
N = 4, M = 2
value[] = {1,3,5,9}
pairs[] = {{1,1},{3,4}}
Output: 1
Explanation: In the given testcase ,
applying the method as stated in the
above example, the output will be 1.
Your Task:
The task is to complete the function copyList() which takes one argument the head of the linked list to be cloned and should return the head of the cloned linked list.
NOTE : If their is any node whose arbitrary pointer is not given then its by default null.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 100
1 <= M <= N
1 <= a, b <= 100

Algorithm:
save the two list nodes parallely in a hash map using next ptr and set the arb ptr.
  ****/

/*  the node structure is as follows

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

void print(Node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}
// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    unordered_map<Node*, Node*> um;

    Node* p1 = head;
    Node* head2 = nullptr;
    Node* p2 = nullptr;

    while(p1) {
        if(!head2) {
            head2 = p2 = new Node(p1->data);
        }
        else {
            p2->next = new Node(p1->data);
            p2 = p2->next;
        }
        um[p1]=p2;
        p1 = p1->next;
    }
    for(auto it : um) {
        auto arb_it = um.find(it.first->arb);
        if(arb_it != um.end())
            it.second->arb = arb_it->second;
    }
    return head2;
}


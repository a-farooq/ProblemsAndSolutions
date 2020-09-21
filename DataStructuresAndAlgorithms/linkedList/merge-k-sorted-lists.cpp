/****
Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 10^3
  ****/

/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/

Node* merge2SortedLists(Node* p1, Node* p2)
{
	if(!p1) return p2;
	if(!p2) return p1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while(p1 && p2) {
        if(p1->data < p2->data) {
            if(!head) head = tail = p1;
            else {
                tail->next = p1;
                tail = tail->next;
            }
            p1 = p1->next;
        }
        else {
            if(!head) head = tail = p2;
            else {
                tail->next = p2;
                tail = tail->next;
            }
            p2 = p2->next;
        }
    }
    if(p1) tail->next = p1;
    else tail->next = p2;
    return head;
}
/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
Node * mergeKLists(Node *arr[], int N)
{
    if(N==0) return nullptr;
    //if(N==1) return arr[0];

    Node* p1 = arr[0];
    for(int i=1; i<N; i++) {
        Node* p2 = arr[i];
        p1 = merge2SortedLists(p1, p2);
    }
    return p1;
}

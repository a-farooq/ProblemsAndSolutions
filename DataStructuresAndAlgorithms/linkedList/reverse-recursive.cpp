/**********
Given a linked list of N nodes. The task is to reverse this list.

Input:
The first line of input contains the number of test cases T. For each test case, the first line contains the length of the linked list and the next line contains the elements of the linked list.

Output:
For each test case, print the reversed linked list in a new line.

User Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 104

Example:
Input:
2
6
1 2 3 4 5 6
5
2 7 8 9 10
Output:
6 5 4 3 2 1
10 9 8 7 2

Explanation:
Testcase 1: After reversing the list, elements are 6->5->4->3->2->1.
Testcase 2: After reversing the list, elements are 10->9->8->7->2.
**********/

#include<iostream>
using namespace std;
//Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;

	Node(int d) : data(d), next(NULL) {}
};

struct Node* reverseList(struct Node *head);

Node* reverseList_rec(Node* head, Node* prev=nullptr)
{
	if(!head) return nullptr;

	Node* ret = reverseList_rec(head->next, head);
	
	head->next = prev;

	if(ret) return ret;
	return head;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		Node* head = NULL;
		Node* curnode = NULL;
		cin >> n;
		while(n--)
		{
			int d;
			cin >> d;
			Node* newnode = new Node(d);

			if(curnode) { curnode->next = newnode; curnode = newnode; }
			else { curnode = newnode; head = newnode; }
		}
		//head = reverseList(head);
		head = reverseList_rec(head);
		Node* tmp = head;
		while(tmp) {
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
		tmp = head;
		while(tmp)
		{
			head = head->next;
			delete tmp;
			tmp = head;
		}
	}
}

struct Node* reverseList(struct Node *head)
{
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


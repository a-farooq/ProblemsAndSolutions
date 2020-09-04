/****
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N,N is the number of elements in Linked List.
The second line of each test case contains N input,elements in Linked List.

Output:

Print the all even numbers then odd numbers in the modified Linked List.

Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100
1 ≤ size of elements ≤ 1000

Example:

Input
3
7
17 15 8 9 2 4 6
4
1 3 5 7
7
8 12 10 5 4 1 6

Output
8 2 4 6 17 15 9
1 3 5 7
8 12 10 4 6 5 1
  ****/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

void print(Node* head)
{
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* segregate(Node* head)
{
    if(!head) return nullptr;

    Node* evenhead = nullptr;
    Node* eventail = nullptr;
    Node* oddhead = nullptr;
    Node* oddtail = nullptr;

    while(head) {
        //cout << head->data << " ";
        if(head->data%2==0) {
            if(!eventail) {
                evenhead = eventail = head;
            }
            else {
                eventail->next = head;
                eventail = eventail->next;
            }
        }
        else {
            if(!oddtail) {
                oddhead = oddtail = head;
            }
            else {
                oddtail->next = head;
                oddtail = oddtail->next;
            }
        }
        head = head->next;
    }

    if(oddtail) oddtail->next = nullptr;
    else if(eventail) eventail->next = nullptr;

    if(evenhead) eventail->next = oddhead;
    else evenhead = oddhead;

    return evenhead;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, d;
	    cin >> n;
	    Node* head = nullptr;
	    Node* tail = nullptr;
	    for(int i=0; i < n; i++) {
	        cin >> d;
	        Node* node = new Node(d);
	        if(!head) {
	            head = tail = node;
	        }
	        else {
	            tail->next = node;
	            tail = node;
	        }
	    }
	    //print(head);
	    head = segregate(head);
	    print(head);
	}
	return 0;
}

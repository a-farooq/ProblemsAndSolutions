/***********
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Input:
The first line of input contains the number of test cases T. For each test case, the first line of input contains the length of the first linked list and next line contains N elements of the linked list. Again, the next line contains M, and the following line contains M elements of the linked list.

Output:
Output the resultant linked list.

User Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)

Constraints:
1 <= T <= 100
1 <= N, M <= 5000

Example:
Input:
2
2
4 5
3
3 4 5
2
6 3
1
7
Output:
3 9 0  
7 0

Explanation:
Testcase 1: For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Testcase 2: For the given two linked list (6 3) and (7), after adding the two linked list resultant linked list will be (7 0).
***********/

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

struct Node* reverseList(struct Node* head)
{
    struct Node* p1 = head;
    if(!p1->next) return head;
    
    struct Node* p2 = head->next;
    if(!p2->next) { 
        p2->next = p1; 
        p1->next = NULL; 
        return p2;
    }
    
    struct Node* p3 = p2->next;
    p1->next = NULL;
    while(p3)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if(!first) return second;
    if(!second) return first;
    
    first = reverseList(first);
    second = reverseList(second);
    
    int carry = 0;
    struct Node* temp = NULL;
    struct Node* newnode = NULL;
    
    while(first != NULL || second != NULL || carry != 0)
    {
        int newval = carry;
        if(first) newval += first->data;
        if(second) newval += second->data;
        
        //cout << "newval: " << newval << endl;
        //cout << "carry: " << carry << endl;
        
        carry = newval/10;
        newval = newval % 10;
        
        newnode = new Node(newval);
        newnode->next = temp;
        temp = newnode;
        
        if(first) first = first->next;
        if(second) second = second->next;
    }
    return newnode;
}

struct Node* addTwoLists2(struct Node* first, struct Node* second)
{
    // code here
    if(!first) return second;
    if(!second) return first;
    
    first = reverseList(first);
    second = reverseList(second);
    
    struct Node* sum = first;
    struct Node* temp = sum;
    struct Node* carryNode = second;
    
    int carry = 0;
    while(first && second)
    {
        int data = first->data + second->data + carry;
        first->data = data%10;
        carry = data/10;
        
        temp = first;
        first = first->next;
        second = second->next;
    }
    
    if(!first) {
        temp->next = second;
        while(second) {
            int data = second->data + carry;
            second->data = data%10;
            carry = data/10;
            
            temp = second;
            second = second->next;
        }
    }
    else {
        while(first) {
            int data = first->data + carry;
            first->data = data%10;
            carry = data/10;
            
            temp = first;
            first = first->next;
        }
    }
    if(carry) {
        carryNode->data = carry;
        temp->next = carryNode;
        carryNode->next = NULL;
    }
    
    sum = reverseList(sum);
    return sum;
}

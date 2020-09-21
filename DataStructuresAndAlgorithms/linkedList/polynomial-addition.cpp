/****
Given two polynomial numbers represented by a linked list. The task is to complete the  function addPolynomial() that adds these lists meaning adds the coefficients who have same variable powers.

Example 1:

Input:
LinkedList1:  (1,x2) 
LinkedList2:  (1,x3)
Output:
1x^3 + 1x^2
Explanation: Since, x2 and x3 both have
different powers as 2 and 3. So, their
coefficient can't be added up.
Example 2:

Input:
LinkedList1:  (1,x3) -> (1,x2)
LinkedList2:  (3,x3) -> (4,x2)
Output:
4x^3 + 6x^2
Explanation: Since, x3 has two different
coefficients as 3 and 1. Adding them up
will lead to 4x3. Also, x2 has two
coefficients as 4 and 2. So, adding them
up will give 6x2.
Your Task:
The task is to complete the function addPolynomial() which should add the polynomial with same powers return the required polynomial in decreasing order of the power in the form of a linked list.
Note: Try to solve the question without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N, M <= 10^5
1 <= x, y <= 10^6

Solution:
Iterate over both lists simultaneously.

If power is same add coefficients, otherwise pick the higher power coefficient
  ****/

/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }

};
*/

/* The below method print the required sum of polynomial
p1 and p2 as specified in output  */
Node* addPolynomial(Node *p1, Node *p2)
{
    if(!p1) return p2;
    if(!p2) return p1;

    Node* head = nullptr;
    Node* tail = nullptr;

    //Your code here
    while(p1 && p2)
    {
        if(p1->pow == p2->pow) {
            p1->coeff += p2->coeff;

            if(!head) head = tail = p1;
            else {
                tail->next = p1;
                tail = tail->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->pow > p2->pow) {
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


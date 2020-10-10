/****
Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list . Then in the next line are N space separated values of the given linked list.

Output:
For each test case output will be the required max length of the palindrome present in the given linked list.

User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.

  ****/

/* The Node is defined
  // * Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    //Your code here
    Node* p1 = head;
    Node* p2 = head->next;
    p1->next = nullptr;
    int maxlen = 1;
    //reverse list one node at a time and traverse in both directions
    //to check even and odd length palindromes
    while(p2) {
        int len = 0;
        Node*q1, *q2;

        //checking even length palindromes
        if(p1->data == p2->data) {
            len=2;
            q1 = p1->next;
            q2 = p2->next;
            while(q1 && q2 && q1->data == q2->data) {
                len += 2;
                q1 = q1->next;
                q2 = q2->next;
            }
        }
        //checking odd length palindromes
        else if(p2->next && p1->data == p2->next->data) {
            len = 3;
            q1 = p1->next;
            q2 = p2->next->next;
            while(q1 && q2 && q1->data == q2->data) {
                len += 2;
                q1 = q1->next;
                q2 = q2->next;
            }
        }
        Node* p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        maxlen = max(maxlen, len);
    }
    //cout << maxlen << endl;
    return maxlen;
}

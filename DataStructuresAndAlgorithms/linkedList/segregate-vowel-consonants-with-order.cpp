/****
Given a singly linked list of size N containing only English Alphabets. Your task is to complete the function arrangeC&V(), that arranges the consonants and vowel nodes of the list it in such a way that all the vowels nodes come before the consonants while maintaining the order of their arrival.

Input:
The function takes a single argument as input, the reference pointer to the head of the linked list. There will be T test cases and for each test case the function will be called separately.

Output:
For each test case output a single line containing space separated elements of the list.

User Task:
The task is to complete the function arrange() which should arrange the vowels and consonants as required.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
6
a e g h i m
3
q r t

Output:
a e i g h m
q r t

Explanation:
Testcase 1: Vowels like a, e and i are in the front, and consonants like g, h and m are at the end of the list.

  ****/

/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/
bool isVowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    return false;
}
// task is to complete this function
// function should return head to the list after making
// necessary arrangements
struct Node* arrange(Node *head)
{
    Node* vowhead = nullptr;
    Node* vowtail = nullptr;
    Node* conhead = nullptr;
    Node* contail = nullptr;

    while(head) {
        if(isVowel(head->data)){
            if(!vowtail) vowhead = vowtail = head;
            else {
                vowtail->next = head;
                vowtail = head;
            }
        }
        else {
            if(!contail) conhead = contail = head;
            else {
                contail->next = head;
                contail = head;
            }
        }
        head = head->next;
    }
    if(contail) {
        contail->next = nullptr;
        if(vowhead) vowtail->next = conhead;
        else vowhead = conhead;
    }
    else vowhead->next = nullptr;
    return vowhead;
}


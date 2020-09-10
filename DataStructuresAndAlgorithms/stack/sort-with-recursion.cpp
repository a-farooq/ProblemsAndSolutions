/****
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity : O(N*N)
Expected Auixilliary Space : O(N) recursive.

Constraints:
1<=N<=100

  ****/

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void insertSorted(int x, stack<int>&s)
{
    if(s.empty() || x > s.top())
    {
        s.push(x);
        return;
    }
    
    int y = s.top();
    s.pop();
    insertSorted(x, s);
    s.push(y);
}
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
    if(s.empty())
        return;
    int x = s.top();
    s.pop();
    sort();
    insertSorted(x, s);
}

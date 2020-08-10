/*********
Implement a Stack using two queues q1 and q2.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow.
First line of each test case contains an integer Q denoting the number of queries . 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the stack)
(ii) 2     (a query of this type means to pop element from stack and print the poped element)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out from the stack.

Your Task:
Since this is a function problem, you don't need to take inputs. You are required to complete the two methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack and pop() which returns the integer poped out from the stack.

Expected Time Complexity: O(1) for push() and O(N) for pop() (or vice-versa).
Expected Auxiliary Space: O(1) for both push() and pop().

Constraints:
1 <= T <= 100
1 <= Q <= 100
1 <= x <= 100

Example:
Input:
2
5
1 2 1 3 2 1 4 2
4
1 2 2 2 1 3
Output:
3 4
2 -1

Explanation:
Testcase1:
1 2    the stack will be {2}
1 3    the stack will be {2 3}
2       poped element will be 3 the stack will be {2}
1 4    the stack will be {2 4}
2       poped element will be 4  
Testcase 2: 
1 2 the stack will be {2}
2    poped element will be 2
2    the stack is empty hence -1
1 3 the stack will be {3}.
********/



/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    int res;
    
    if(q1.empty()) return -1;
    
    int i = 1;
    while(i++ < q1.size())
    {
        q1.push(q1.front());
        q1.pop();
    }
    res = q1.front();
    q1.pop();
    return res;
}


/****
Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, youmust take i steps. Given a destination D , find the minimum number of steps required to reach that destination.

Example 1:

Input: D = 2
Output: 3
Explaination: The steps takn are +1, -2 and +3.
Example 2:

Input: D = 10
Output: 4
Explaination: The steps are +1, +2, +3 and +4.
Your Task:
You do not need to read input or print anything. Your task is to complete the function minSteps() which takes the value D as input parameter and returns the minimum number of steps required to reach the dedstination D from 0.

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ D ≤ 10000
  ****/

// User function Template for C++

class Solution{
    int countSteps(int src, int steps, int dest)
    {
        if(abs(src)>dest)
            return INT_MAX;
        if(src == dest)
            return steps;

        int pos = countSteps(src+steps+1, steps+1, dest);

        int neg = countSteps(src-steps-1, steps+1, dest);

        return min(pos, neg);
    }
    int countSteps(int dest)
    {
        dest = abs(dest);

        int sum=0, steps=0;
        while(sum<dest || (sum-dest)%2 != 0) {
            steps++;
            sum += steps;
        }
        return steps;
    }
public:
    int minSteps(int D)
    {
        // code here
        return countSteps(D);
    }
};

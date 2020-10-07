/****
Given a binary number, Find, if given binary number is a multiple of 3. The given number can be big upto 2^10000. It is recommended to finish the task using one traversal of input binary string.

Example 1:

Input: S = "011"
Output: 1
Explanation: "011" decimal equivalent
is 3, which is divisible by 3.

Example 2:

Input: S = "100"
Output: 0
Explanation: "100" decimal equivalent
is 4, which is not divisible by 3.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isDivisible() which takes the string s as inputs and returns 1 if the given number is divisible by 3 otherwise 0.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |S| ≤ 10^5
  ****/

//User function template for C++
class Solution{
public:

	int isDivisible(string s){
	    //complete the function here
	    bool flag=true;
	    int c1=0;
	    int c2=0;
	    for(auto ch:s) {
	        if(ch=='1') {
	            if(flag)
	                c1++;
	            else
	                c2++;
	        }
	        flag = !flag;
	    }
	    //if diff of count of set bits at odd and even pos is divisible by 3
	    //return true else false
	    return abs(c1-c2)%3==0?1:0;
	}

};

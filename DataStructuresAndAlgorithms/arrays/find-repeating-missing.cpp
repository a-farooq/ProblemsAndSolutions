/****
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 10^5
1 ≤ Arr[i] ≤ N

Solution:
1. Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.

2. Make two equations:

Let x be the missing and y be the repeating element.

Get the the sum of all numbers using formula S = n(n+1)/2 – x + y

Get product of all numbers using formula P = 1*2*3*…*n * y / x

The above two steps give us two equations, we can solve the equations and get the values of x and y.
To overcome overflow of sum and product you sholud use long long
  ****/

class Solution{

public:
    int *findTwoElement(int *arr, int n) {
        int *out = new int[2];
        /*
        long long sum = 0;
        long long prod=1;
        long long prod_real = 1;
        long long sum_real = 0;
        for (int i=0; i<n; i++) {
            sum += arr[i];
            prod *= arr[i];
            prod_real *= (i+1);
            sum_real += i+1;
        }
        //cout << sum << ", "<< prod << endl;

        //cout << sum_real << ", "<< prod_real << endl;

        out[1] = prod_real*(sum-sum_real)/(prod-prod_real);
        out[0] = sum + out[1] - sum_real;
        */
        int hash[n+1];

        fill_n(hash, n+1, 0);

        for (int i=0; i<n; i++) {
            if(hash[arr[i]]==0) {
                hash[arr[i]]=-1;
            }
            else out[0]=arr[i];
        }
        for (int i=1; i<=n; i++) {
            if(hash[i]==0)
                out[1]=i;
        }

        return out;
    }
};

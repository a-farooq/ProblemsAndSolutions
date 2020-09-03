/****
Given an array A of N integers. The task is to find a peak element in A in O( log N ) .
An array element is peak if it is not smaller than its neighbours. For corner elements, consider only one neighbour.

Example 1:

Input:
N = 3
A[] = {1,2,3}
Output: 2 
Explanation: In the given array, 
3 is the peak element as it is 
greater than its neighbour.
Example 2:

Input:
N = 2
A[] = {3,4}
Output: 1
Explanation: 4 is the peak element 
as it is greater than its neighbour 
elements.
Your Task:
You don't have to read input or print anything. Just complete the provided function peakElement() and return a valid index with respect to 0 based indexing.
Note 1: Multiple peak element may be possible, in that case return any of the valid index .
Note 2: If you click on Compile and Test the output will be 1 if the index that you return is correct. Otherwise output will be 0. 

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^5
1 <= A[] <= 10^6
  ****/
/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int a[], int n)
{
    //cout << "n: " << n << endl;
    if(n==1) return 0;
    //if(a[0]>a[1]) { return 0; }
    //if(a[n-1]>a[n-2]) { return n-1; }
    
    int l = 0, r = n-1, mid=-1;
    while(l<r) {
        if(a[l]>a[l+1]) return l;
        if(a[r]>a[r-1]) return r;
        
        mid = l+(r-l)/2;
        if(a[mid-1] < a[mid] && a[mid+1] < a[mid]) 
            return mid;
        
        else if(a[mid-1]>a[mid])
            r=mid-1;
        
        else if(a[mid+1]>a[mid]) 
            l=mid+1;
    }
    return -1;
}

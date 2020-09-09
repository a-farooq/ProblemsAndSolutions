/****
The task is to complete merge() function which is used to implement Merge Sort.

Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output: 1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output: 1 2 3 4 5 6 7 8 9 10
Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes the array arr[], the starting position of the first array (l),  the ending position of the first array (m) and the ending position of the second array (r) as its inputs and modifies the array arr[] such that it is sorted from position l to position r. The range [l,m] and [m+1,r] are already sorted.

Expected Auxiliary Space: O(n)
Expected Time Complexity: O(n)  (for the merge() function) 

Constraints:
1 <= N <= 10^5
1 <= arr[i] <= 10^3
  ****/

/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */

// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
     // Your code here
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];

    int j = 0;
    for(int i = l; i <= m; i++)
        L[j++] = arr[i];
    j = 0;
    for(int i = m+1; i <= r; i++)
        R[j++] = arr[i];

    j = 0;
    int i = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while(i < n1) arr[k++] = L[i++];

    while(j < n2) arr[k++] = R[j++];
}

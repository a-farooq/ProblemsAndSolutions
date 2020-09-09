/****
Given an array of integers. Complete the partition() function used for the implementation of Quick Sort.

Example 1:

Input: N = 5, arr[] = { 4, 1, 3, 9, 7}
Output: 1 3 4 7 9
Example 2:

Input: N = 10, 
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output: 1 2 3 4 5 6 7 8 9 10

Your Task: You don't need to read input or print anything. Your task is to complete the function partition() which takes the array arr[] and the range of indices to be considered [low, high] and partitions the array in the given range considering the last element as the pivot such that, all the elements less than(or equal to) the pivot lie before the elements greater than it. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 10^3
1 <= arr[i] <= 10^4
  ****/

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}*/

/* This function takes last element as pivot, places  the pivot element
   at its correct position in sorted  array, and places all smaller (smaller
   than pivot) to left of pivot and all greater elements to right  of pivot */
int partition (int arr[], int low, int high)
{
   // Your code here
    int i = low-1;
    int pivot = arr[high];

    for(auto j = low; j < high; j++)
    {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

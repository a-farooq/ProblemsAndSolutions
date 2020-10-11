/****
Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^7
1 ≤ C ≤ 10^18

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
  ****/

#include <iostream>
using namespace std;


// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
long merge(int arr[], int tmp[], int l, int m, int r)
{
    long inv_cnt = 0;

    int i=l, j=m, k=l;
    while((i<=m-1) && (j<=r)) {
        if(arr[i]<=arr[j])
            tmp[k++]=arr[i++];
        else {
            tmp[k++]=arr[j++];
			//enhancement to traditional merge sort
			//adds the count of numbers more than arr[j] in left subarray
            inv_cnt=inv_cnt+(m-i);
        }
    }
    while(i<=m-1)
        tmp[k++]=arr[i++];

    while(j<=r)
        tmp[k++]=arr[j++];

	//copy back into original array
    for(i=l; i<=r; i++)
        arr[i]=tmp[i];

    return inv_cnt;
}

long mergeSort(int arr[], int tmp[], int l, int r)
{
    long inv_cnt=0;

    if (l < r)   {
        int m = l+(r-l)/2;
        //int m = (l+r)/2;
        inv_cnt += mergeSort(arr, tmp, l, m);
        inv_cnt += mergeSort(arr, tmp, m+1, r);
        inv_cnt += merge(arr, tmp, l, m+1, r);
    }
    return inv_cnt;
}

long mergeSortUtil(int arr[], int n)
{
    int tmp[n];
    return mergeSort(arr, tmp, 0, n-1);
}

int naive_method(int* a, int n)
{
    int inv_count=0;
	for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(a[j]<a[i])
                inv_count++;

    return inv_count;
}

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i=0; i<n; i++)
	        cin >> a[i];

	    //cout << naive_method(a,n) << endl;

	    cout << mergeSortUtil(a, n) << endl;
	}
	return 0;
}

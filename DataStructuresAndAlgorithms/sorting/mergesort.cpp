#include<iostream>
using namespace std;


void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];

		mergeSort(arr, 0, n-1);

		for(int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}

/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

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

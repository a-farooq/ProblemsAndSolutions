#include <iostream>
using namespace std;

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high); 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(auto i = 0; i < n; i++) {
			cin >> arr[i];
		}
		quickSort(arr, 0, n-1);

		for(auto i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,    low  --> Starting index,   high  --> Ending index
*/
void quickSort(int arr[], int low, int high) 
{
    if (low < high)     {
        // pi is partitioning index, arr[p] is now  at right place
        int pi = partition(arr, low, high);
        // Separately sort elements before / partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
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

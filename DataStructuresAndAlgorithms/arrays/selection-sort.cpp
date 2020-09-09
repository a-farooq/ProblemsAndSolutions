/****


  ****/

int select(int arr[], int i)
{
    // code here such that selecionSort() sorts arr[]
    int maxi = -100000;
    int ind=i;
    for(int j=0; j<=i; j++) {
        if(maxi<arr[j]) {
            maxi=arr[j];
            ind=j;
        }
    }
    return ind;
}


void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)
   {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
   }
}

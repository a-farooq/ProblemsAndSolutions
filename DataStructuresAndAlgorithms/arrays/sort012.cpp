/****
Given an array of size N containing 0s, 1s, and 2s; sort the array in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which will contain N. The second lines contains the elements of the array.

Output: 
Print sorted array.

Your Task:
Complete the function sort012() that takes array and n and sorts the array in place. 

Constraints: 
1 <= T <= 50
1 <= N <= 10^5
0 <= A[i] <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1
Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.
  ****/

void sort012(int a[], int n)
{
    int i0=0, i1=0, i2=n-1;
    while(a[i0]==0) i0++;
    while(a[i2]==2) i2--;

    i1=i0;
    while(i1<n) {
        if(a[i1]==0)
            swap(a[i0++], a[i1]);

        i1++;
    }
    i1=i0;
    while(i1<n) {
        if(a[i1]==1)
            swap(a[i0++], a[i1]);

        i1++;
    }
    /*
    while(i1<=i2 && i1>=i0) {
        if(a[i1]==0) {
            swap(a[i0++], a[i1]);
            while(a[i0]!=0) i0++;
            while(a[i2]!=2) i2--;
        }
        else if(a[i1]==2) {
            swap(a[i2--], a[i1]);
            while(a[i0]!=0) i0++;
            while(a[i2]!=2) i2--;
        }
        else i1++;
    }*/
    //for(int i=0; i < n; i++) cout << a[i] << " ";
    //cout << endl;
}

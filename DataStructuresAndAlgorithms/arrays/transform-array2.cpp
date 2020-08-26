/****
Given an array of integers of size N. Assume ‘0’ as invalid number and all other as valid number. Write a program that modifies the array in such a way that if next number is  valid number and is same as current number, double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0’s are shifted to the end and the sequence of the valid number or new doubled number is maintained as in the original array.

Examples:

Input : arr[] = {2, 2, 0, 4, 0, 8}
Output : 4 4 8 0 0 0

Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
Output :  4 2 12 8 0 0 0 0 0 0
Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test case follows. First line of each test contains an integer N denoting the size of the array. Then next line contains N space separated integers denoting the elements of the array.

Output:
For each test case print space separated elements of the new modified array on a new line.

Constraints:
1<=T<=10^3
1<=N<=10^5

Example:
Input:
2
5
2 2 0 4 4
5
0 1 2 2 0
Output:
4 8 0 0 0
1 4 0 0 0
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n];
	    for(int i = 0; i < n; i++) cin >> a[i];

	    //first traverse and double the valid numbers
	    for(int i = 0; i < n-1; i++) {
	        if(a[i]!=0 && a[i] == a[i+1]) {
	            a[i] *= 2;
	            a[i+1] = 0;
	        }
        }

        //now, shift all the 0's to right
	    int i = 0, j = 0;

        while(j < n) {
			//move i to first 0
	        while(a[i] != 0)
	            i++;

			//move j to first non zero after i
	        if(j == 0) j = i+1;
	        while(a[j] == 0 && j < n)
	            j++;

	        if(j >= n) break;

	        swap(a[i], a[j]);
	    }

	    for(auto val : a) cout << val << " ";
	    cout << endl;
	}
	return 0;
}

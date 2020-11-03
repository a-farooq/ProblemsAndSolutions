/****
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

For Example:
If the matrix is    

1 2 3
4 5 6
7 8 9
The output should Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
i.e print the elements of array diagonally.

Note: The input array given is in single line and you have to output the answer in one line only.

 

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N depicting the size of square matrix and next line followed by the value of array.


Output:

Print the elements of matrix diagonally in separate line.


Constraints:

1 ≤ T ≤ 30
1 ≤ N ≤ 20
0 ≤ A[i][j] ≤ 9


Example:

Input:
2
2
1 2 3 4
3
1 2 3 4 5 6 7 8 9
Output:
1 2 3 4
1 2 4 3 5 7 6 8 9
  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int a[n][n];

	    for(int i=0; i<n; i++)
	        for(int j=0; j<n; j++)
    	        cin >> a[i][j];

		//first print upper half diagonal
		//then lower half

		//both subscripts i & j must be in same loop
		//as they vary together
    	for(int k=0; k<n; k++)
    	    for(int i=0, j=k; i<n && j>=0; i++, j--)
    	        cout << a[i][j] << " ";


    	for(int k=1; k<n; k++)
    	    for(int i=k, j=n-1; i<n && j>0; i++, j--)
    	        cout << a[i][j] << " ";

    	cout << endl;
	}
	return 0;
}

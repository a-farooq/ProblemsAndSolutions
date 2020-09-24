/****
Given a 2D array, find the maximum sum subarray in it. For example, in the following 2D array, the maximum sum subarray is highlighted with blue rectangle and sum of this subarray is 29.

                                                          

Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29

Algorithm:
https://www.youtube.com/watch?v=yCQN096CwWM

For each rectangle of columns (starting from left to right), get sum in an array and apply Kadane algo to find max Sum
over the 1D array
  ****/

#include <iostream>
#include <climits>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int row, col;
	    cin >> row >> col;
	    int mat[row][col];
	    for(int i=0; i<row; i++) {
	        for(int j=0; j<col; j++) {
	            cin >> mat[i][j];
	        }
	    }

	    int aux[row];
	    int left, right;
	    int maxSum=0;
	    int curSum=0;
	    //int rectLeft=0, rectRight=0, rectTop=0, rectDown=0;
	    left = 0;
	    while(left < col) {

	        for(int i=0; i<row; i++) {
	            aux[i] = 0;
	        }

	        right = left;
	        while(right < col) {
	            for(int i=0; i<row; i++) {
	                aux[i] += mat[i][right];
	            }

	            //kadane's algo
	            {
	                int msf = INT_MIN;
	                int meh = 0;
	                for(int i=0; i<row; i++) {
	                    meh = meh+aux[i];
	                    if(meh < aux[i])
	                        meh = aux[i];
	                    if(msf < meh) {
	                        msf = meh;
	                        //rectDown = i;
	                    }
	                }
	                curSum = msf;
	            }

	            if(curSum > maxSum) {
	                maxSum = curSum;
	                //rectLeft = left;
	                //rectRight = right;
	            }
	            right++;
	        }
	        left++;
	    }
	    cout << maxSum << endl;
	}
	return 0;
}

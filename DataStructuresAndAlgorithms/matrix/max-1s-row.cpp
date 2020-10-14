/****
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 10^3
0 ≤ Arr[i][j] ≤ 1
  ****/

int binary_search(vector<int> a, int l, int r)
{

    while(l<r)
    {
        int mid = l+(r-l)/2;
        if(a[mid]==0) {
            if(a[mid+1]==1)
                return mid+1;
            else l=mid;
        }
        else {
            if(a[mid-1]==0)
                return mid;
            else r=mid;
        }
    }
}

//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int m, int n)
	{
	    // code here
	    int res_idx = 0;
        int i=0;
        //find first row with at least one 1
        for(; i<m; i++)
            if(arr[i][n-1])
                break;

        //all are 0s
        if(i==m)
            return -1;
        //row i has all 1s
        else if(arr[i][0])
            return i;
        else {
            //row i has first 1 at col j
            int j=binary_search(arr[i], 1, n-1);

            //iterate for all rows after i
            for(int k=i+1; k<m; k++) {
                //row k has all 1s
                if(arr[k][0])
                    return k;

                //find if row k has any 1 left of col j
                //update j
                //save row k
                if(arr[k][j-1]==1) {
                    j=binary_search(arr[k], 0, j-1);
                    res_idx=k;
                }
            }
        }
        return res_idx;
	}

};

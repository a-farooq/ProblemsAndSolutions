/****
Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and return segment which has maximum length.
NOTE 2: If there is still a tie, then return the segment with minimum starting index.

Example 1:

Input:
N = 3
A[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.
Example 2:

Input:
N = 2
A[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.
 

Your Task:
Complete the function findSubarray() which takes the array a and the size of the array, n, as input parameters and returns an array representing the answer. If there is no subarray return an array of length 1 containing -1 only. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
-105 ≤ A[i] ≤ 105


  ****/

//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    long long maxsum=0, sum=0, maxstart=0, start=0, maxlen=0, len=0;
	    int i=0;
	    while(true)
	    {
	        if(i==n || a[i]<0) {
	            if(maxsum < sum) {
	                maxsum = sum;
	                maxlen = len;
	                maxstart = start;
	            }
	            else if(maxsum == sum) {
	                if(maxlen < len) {
	                    maxlen = len;
	                    maxstart = start;
	                }
	                else if(maxlen == len) {
	                    maxstart = min(maxstart, start);
	                }
	            }

	            //cout << maxsum <<", "<<maxstart<<", "<<maxlen<<endl;

	            if(i==n) break;

	            sum = 0;
	            len = 0;
	        }
	        else if(a[i] >= 0) {
	            sum += a[i];
	            if(len==0)
	                start = i;
	            len++;
	        }
	        i++;
	    }
	    vector<int> res;
	    for(int i=maxstart; i<maxstart+maxlen; i++)
	        res.push_back(a[i]);

	    if(res.empty()) res.push_back(-1);
	    return res;
	}
};

/****
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

Example 1:

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
Your task:
You do not need to read any input or print anything. The task is to complete the function lps(), which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets

Solution:
Use preprocessing algorithm of KMP.
  ****/

class Solution{
public:


	int lps(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    int arr[n];
	    fill_n(arr, n, 0);
	    int i=0, j=1, k=1;

	    while(j<n)
	    {
	        if(s[i]==s[j]) {
	            arr[j++]=++i;
	            //j++;
	        }
	        else
            {
                if (i != 0)
                    i = arr[i - 1];

                else
                    j++;
            }
	        /*
	        if(s[i]==s[j]) {
	            arr[j]=k++;
	            i++;
	            j++;
	        }
	        else {
	            if(k==1) {
	                j++;
	                i=0;
	            }
	            else {
	                i=0;
	                j -= arr[j-1]-1;
	                k=1;

	                //i=arr[j-1]-1;
	                //k=arr[j-1];
	            }
	            //k=1;
	        }
	        */
	    }
	    /*
	    for(auto val : arr)
	        cout << val << " ";
	    cout << endl;*/
	    return arr[n-1];
	}
};

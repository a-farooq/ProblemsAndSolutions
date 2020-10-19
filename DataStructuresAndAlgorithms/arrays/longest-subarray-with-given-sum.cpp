/****
Given an array containing N integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains two Integers N and K and the second line contains N space separated elements of the array.

Output:
For each test case, print the required lenght of the longest Sub-Array in new line. If no such sub array can be formed print 0.

Constraints:
1<=T<=500
1<=N,K<=105
-105<=A[i]<=105

Example:
Input:
3
6 15
10 5 2 7 1 9
6 -5
-5 8 -14 2 4 12
3 6
-1 2 3
Output:
4
5
0
Explanation:
TestCase 1:

Input : arr[] = { 10, 5, 2, 7, 1, 9 }, 
K = 15
Output : 4
The sub-array is {5, 2, 7, 1}.
  ****/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin >> a[i];

	    unordered_map<int,int> um;
	    int maxlen=0;
	    int sum=0;
	    um[0]=-1;//for subarray starting at 0
	    for(int i=0; i<n; i++) {

            sum+=a[i];

            //if(um.find(sum)==um.end())
            //    um[sum]=i; //overwrites

			//doesnt overwrite
            um.insert(make_pair(sum, i));

            auto iter = um.find(sum-k);
            if(iter!=um.end()) {
                maxlen=max(maxlen, i-iter->second);
            }

	    }
	    /*
	    for(auto iter : um) {
	        cout << iter.first <<"=>";
	        cout << iter.second << endl;
	    }
        */
	    /*
	    while(j<n)
	    {
	        if(sum==k) {
	            maxlen=max(maxlen, j-i+1);
	            j++;
	            sum+=a[j];
	        }
	        else if(sum > k) {
	            sum-=a[i];
	            i++;
	        }
	        else {
	            j++;
	            sum+=a[j];
	        }
	    }
	    if(sum==k)
	        maxlen=max(maxlen, j-i+1);
	        */
	    cout << maxlen << endl;
	}
	return 0;
}

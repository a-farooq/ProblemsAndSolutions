/****
Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Output:
For each test case in a new line print the length of the smallest such string.

Constraints:
1 <= T <= 100
1 <= |S| <= 105

Example:
Input:
2
aabcbcdbca
aaab

Output:
4
2

Explanation:
Testcase 1: Smallest window size is 4 which is of "dbca" which consists all characters of the string.


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
	    string str;
	    cin >> str;

		//hash arrays for pattern and string to count char occurences
	    int hash_pat[256] = {0};
	    int hash_str[256] = {0};

	    int pat_len=0;

		//prepare hash_pat first
	    for(char ch : str) {
	        if(hash_pat[ch]==0) {
    	        hash_pat[ch]++;
    	        pat_len++;
	        }
	    }
	    //cout << "pat len: "<<pat_len << endl;

	    int cnt=0;
	    int start=0;
	    int min_len=INT_MAX;

		//iterate over the string
	    for(auto i=0; i<str.length(); i++) {
	        char ch = str[i];

			//update hash array
	        hash_str[ch]++;

			//update count for only first occurence of char in str
	        if(hash_str[ch] == 1 && hash_pat[ch]>0) {
				//set tentative start of window
	            if(cnt==0) start=i;
	            cnt++;
	        }

			//shrink window for every char traversed
	        if(cnt==pat_len) {
				//update start and hash array if window has duplicate of all chars
	            while(hash_str[str[start]]>1) {
	                hash_str[str[start]]--;
	                start++;
	            }
	            min_len=min(min_len, i-start+1);
	        }
	        //cout << "ch: "<<ch<<", cnt: "<<cnt<<", start: "<<start<<endl;
	        //cout << "min len: "<<min_len<<endl;
	    }

	    cout << min_len << endl;

	}
	return 0;
}

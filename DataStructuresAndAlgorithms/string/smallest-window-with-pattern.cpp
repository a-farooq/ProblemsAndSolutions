/****
Given a string S and text T. Output the smallest window in the string S having all characters of the text T. Both the string S and text T contains lowercase english alphabets.

Input:
First line of the input contains an integer T, denoting the number of test cases. Then T test case follows. Each test contains 2 lines having a string S and next line contains text T.

Output:
Output the smallest window of the string containing all the characters of the text. If such window doesn`t exist or this task can not be done then print -1.

Constraints:
1 <= T <= 100
1 <= |N|, |X| <= 1000

Example:
Input:
2
timetopractice
toc
zoomlazapzo
oza

Output:
toprac
apzo

Explanation:
Testcase 1: "toprac" is the smallest substring in the given string S which contains every characters of T.

Solution:
1. First check if the length of string is less than the length of the given text, if yes then no such window can exist .
Try to use the concept of hashing to solve further cases.
2. Store the occurrence of characters of the given pattern in a hash table.
Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
Check if (count == length of text) this means a window is found.
3. If such window found, try to minimize it by removing extra characters from the beginning of the current window.
Update min_length.
Print the minimum length window.
  ****/

#include <iostream>
#include <unordered_map>
using namespace std;

int shrink_window(int l, int j, string t, string s)//, unordered_map<char,int>& um)
{
    unordered_map<char,int> um;
    for(char ch : t)
	   um[ch]++;
    //for_each(um.begin(), um.end(), [&](int i){ um.erase(i); });
    //for(auto iter=um.begin(); iter != um.end(); iter++) {
    //    iter->second=0;
    //}

    int cnt=0;
    //iterate from right to left to find the smallest window
    //which has all the chars of the pattern
    while(j>=l) {
        if(um.find(s[j]) != um.end()) {
            //pattern can also have duplicates like the string
            //count only if value is positive in hashmap
            if(um[s[j]]>0) {
                um[s[j]]--;
                cnt++;
            }

            //return left of new window
            if(cnt == t.length()) {
                break;
            }
        }
        j--;
    }
    return j;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string s, t;
	    cin >> s >> t;
	    if(t.length() > s.length()) {
	        cout << -1 << endl;
	        continue;
	    }

	    unordered_map<char,int> um;
	    for(char ch : t) {
	        um[ch]++;
	    }

	    //cout << "t.length: "<< t.length() << endl;
	    int minlen = s.length();
	    int j=0, l=0, r=0, cnt=0;
	    bool found = false;
	    while(j < s.length()) {
	        if(um.find(s[j]) != um.end()) {
	            if(um[s[j]]>0) {
    	            um[s[j]]--;
    	            cnt++;
    	            //cout << "cnt: "<<cnt << endl;
	            }


	            if(cnt >= t.length()) {
	                found = true;
	                r=j;

	                //returns left of smallest window possible
	                int start = shrink_window(l, j, t, s);
	                //update left of window with the return value
	                //take the earlier match of pattern with same length window
	                if(r-start+1 < minlen) {
	                    //minlen = min(minlen, r-l+1);
	                    l = start;
	                    minlen=r-l+1;
	                }
	            }
	        }
	        j++;
	    }
	    if(!found)
	        cout << -1 << endl;
	    else
    	    cout << s.substr(l, minlen) << endl;

	}
	return 0;
}

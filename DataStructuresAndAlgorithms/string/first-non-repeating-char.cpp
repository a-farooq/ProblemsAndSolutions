/****
Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string S.

Output:
For each testcase, print the first non repeating character present in string. Print -1 if there is no non repeating character.

Constraints:
1 <= T <= 900
1 <= N <= 104

Example:
Input :
3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

Output :
h
c
-1


  ****/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    //queue to hold first non-repeating char at front
	    queue<char> que;
	    int n;
	    string str;
	    cin >> n >> str;
	    //array to hold frequency of each char
	    int a[26] = {0};
	    for(auto ch : str) {
	        a[ch-'a']++;
	        que.push(ch);
	        while(!que.empty() && a[que.front()-'a'] > 1) {
	            que.pop();
	        }
	    }
	    if(que.empty()) cout << -1 << endl;
	    else cout << que.front() << endl;
	}
	return 0;
}

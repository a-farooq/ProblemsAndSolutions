/****
Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 10^4

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.

  ****/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	//code
	struct Key
	{
	    int freq;
	    char ch;
	    bool operator<(const Key& k) const
	    {
	        return freq < k.freq;
	    }
	};

	int t;
	cin >> t;
	while(t--)
	{
	    int count[26] = {0};
	    string st;
	    cin >> st;

		//heap of chars with freq
	    priority_queue<Key> pq;

		//resultant string
	    string res = "";

		//dummy prev obj
	    Key prev {-1, '#'};

		//populate freq
	    for(auto ch : st)
	        count[ch-'a']++;

		//push into heap
	    for(auto i=0; i<26; i++)
	        if(count[i])
	            pq.push(Key{count[i], 'a'+i});

	    //for(int i=0; i<26; i++)
	    //    cout << count[i] << " "; cout << endl;

	    while(!pq.empty())
	    {
	        Key k = pq.top();
	        pq.pop();

	        //cout << k.ch << endl;
	        res += k.ch;

	        if(prev.freq > 0)
	            pq.push(prev);

	        (k.freq)--;
	        prev = k;
	    }

	    //cout << res << endl;

	    cout << (res.length()==st.length()?1:0) << endl;
	}
	return 0;
}

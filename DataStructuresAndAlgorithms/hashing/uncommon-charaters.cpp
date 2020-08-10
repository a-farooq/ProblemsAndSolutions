/*****

Find and print the uncommon characters of the two given strings S1 and S2. Here uncommon character means that either the character is present in one string or it is present in other string but not in both. The strings contains only lowercase characters and can contain duplicates.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings in two subsequent lines.

Output:
For each testcase, in a new line, print the uncommon characters of the two given strings in sorted order.

Constraints:
1 <= T <= 100
1 <= |S1|, |S2| <= 105

Example:
Input:
1
characters
alphabets
Output:
bclpr
****/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    set<char> hset1, hset2;
	    string s1, s2;
	    cin >> s1 >> s2;

	    for(char ch : s1)
	        hset1.insert(ch);

	    for(char ch : s2)
	        hset2.insert(ch);

	    s2 = std::string(hset2.begin(), hset2.end());
	    //cout << s2 << endl;
	    hset2.clear();

	    for(char ch : s2) {
	        if(hset1.find(ch) != hset1.end())
	            hset2.insert(ch);
	        else hset1.insert(ch);
	    }

	    for(auto k : hset1)
	        if(hset2.find(k) == hset2.end())
	            cout << k;
	    cout << endl;
	}
	return 0;
}

/****
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are anagram of each other or not. An anagram of a string is another string that contains same characters, only the order of characters can be different. For example, “act” and “tac” are anagram of each other.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case consist of two strings in 'lowercase' only, in a single line.

Output:
Print "YES" without quotes if the two strings are anagram else print "NO".

Constraints:
1 ≤ T ≤ 300
1 ≤ |s| ≤ 106

Example:
Input:
2
geeksforgeeks forgeeksgeeks
allergy allergic

Output:
YES
NO

Explanation:
Testcase 1: Both the string have same characters with same frequency. So, both are anagrams.
Testcase 2: Characters in both the strings are not same, so they are not anagrams.

Solution:
Step 1: Take an array of size 26, which will contain the count of characters of first string.
Step 2: Traverse through each character of first string and increment the count of character in the array taken in step 1.
Step 3: Now, traverse the second string and decrement the count of characters in the same array, taken in step 1.
Step 4: At last, just traverse the array and check if there is any value other than 0. If it exists, this means there are some characters which are not in both the string. This is because we have first incremented the count using first string and then decremented the same for the second string.
Step 5: If any of the value is not equal to 0, print NO, else print YES.
  ****/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s1, s2;
	    int hash[26];
	    fill_n(hash, 26, 0);
	    cin >> s1 >> s2;

	    for(char ch : s1)
	        hash[ch-'a']++;

	    for(char ch : s2)
	        hash[ch-'a']--;

	    int i=0;
	    for(; i<26; i++)
	        if(hash[i]!=0)
	            break;

	    if(i==26) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
	return 0;
}

/****
Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is String str.

Output:
Print length of smallest substring with maximum number of distinct characters.
Note: The output substring should have all distinct characters.

Constraints:
1 ≤ T ≤ 100
1 ≤ size of str ≤ 10000

Example:
Input:
2
abababcdefababcdab
geeksforgeeks

Output:
6
7
  ****/

#include <iostream>
#include <array>
using namespace std;

int main() {
    array<int, 26> alp; // {-1};

    //for (int i = 0; i < 26; i++)
    //    cout << alp[i] << " ";
    //cout << endl;

    int t;
    cin >> t;
    while(t--)
    {
        alp.fill(-1);
        string str;
        cin >> str;
        int len = str.length();
        int i = 0, j = 0;
        int maxi = 0;
        while(j < len) {
            char ch = str[j];
            if(alp[ch-'a'] != -1) { //current char was found previously
                int k = alp[ch-'a'];
                if(k >= i) { //update cur window if last occurence of cur char is within cur window
                    maxi = max(maxi, j-i);
                    i=k+1;
                }
            }
            alp[ch-'a']=j;
            j++;
        }
        maxi = max(maxi, j-i);
        cout << maxi << endl;
    }
	return 0;
}

/****
Given a string, the task is to count all palindromic sub-strings present in it.

Input:

The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the length of the string, next line of test case contains the string


Output:

For each test case output a single line depecting the number of palindromic substrings present.


Constraints:

1<=T<=100
2<=N<=500


Example:

Input

2
5
abaab
7
abbaeae

Output

3
4

Explanation:

Test Case 1
Input : str = "abaab"
Output: 3
All palindrome substring are : "aba" , "aa" , "baab"

Test Case 2
Input : str = "abbaeae"
Output: 4
All palindrome substring are : "bb" , "abba" ,"aea","eae"


  ****/

#include <iostream>
using namespace std;

int PalindromeCount(string st)
{
    int count=0;
    int stlen = st.length();
    //int maxi=0;
    //int maxi_start=0;
    for(int k=0; k<stlen; k++) {
        int i=k-1, j=k+1;
        int len=1;
        //int start = k;
        //cout << k << "=>"<< i << "=>" << j << endl;
        //check for odd length palindromes
        while(i>=0 && j<stlen) {
            //cout << "====" << endl;
            if(st[i]!=st[j]) break;
            len+=2;
            //start=i;
            i--;
            j++;
            count++;
        }
        /*
        if(maxi<len) {
            maxi = len;
            maxi_start = start;
        }*/
        //cout << len<< ", "<<maxi_start << ", "<< maxi << endl;
        //check for even length palindromes
        if(k<stlen-1 && st[k]==st[k+1]) {
            i=k-1;
            j=k+2;
            len=2;
            //start=k;
            count++;
            while(i>=0 && j<stlen) {
                if(st[i]!=st[j]) break;
                len+=2;
                //start=i;
                i--;
                j++;
                count++;
            }
            /*
            if(maxi<len) {
                maxi = len;
                maxi_start = start;
            }*/
            //cout << len<<", "<<maxi_start << ", "<< maxi << endl;
        }

    }
    //cout << maxi_start << ", "<< maxi << endl;
    //return st.substr(maxi_start, maxi);
    return count;
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    string str;
	    cin >> str;
	    cout << PalindromeCount(str) << endl;
	}
	return 0;
}

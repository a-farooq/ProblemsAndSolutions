/****
Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in computing palindromes.
You are given a string S containing alphanumeric characters. Find out whether the string is a palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.

Input:
The first line of the input contains T, the number of test cases. T testcases follow.  Each line of the test case contains string 'S'.

Output:
Each new line of the output contains "YES" if the string is palindrome and "NO" if the string is not a palindrome.

Constraints:
1<=T<=100
1<=|S|<=100000
Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

Example:
Input:
2
I am :IronnorI Ma, i
Ab?/Ba

Output:
YES
YES
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--)
	{
	    string st, st2="";
	    getline(cin, st);
	    //cout << st << endl;
	    int len = st.length();
	    //remove any char other than alphabet and digit
	    //take lower of each char
	    for(auto i=0; i<len; i++) {
	        if((tolower(st[i])>='a'&&tolower(st[i])<='z') ||
	            (st[i]>='0'&&st[i]<='9'))
	            st2 += tolower(st[i]);
	    }
	    //cout << st2 << endl;
	    //compare if palindrome
	    bool flag = true;
	    len = st2.length();
	    int i=0,j=len-1;
	    while(i<j) {
	        if(st2[i++]!=st2[j--]) {
	            flag=false; break;
	        }
	    }
	    cout << (flag?"YES":"NO") << endl;
	}
	return 0;
}

/****
Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

Example 1:

Input:
str = aaaabbbccc
Output: a4b3c3
Explanation: a repeated 4 times
consecutively b 3 times, c also 3
times.
Example 2:

Input:
str = abbbcdddd
Output: a1b3c1d
Your Task:
Complete the function encode() which takes a character array as a input parameter and returns the encoded string.

Expected Time Complexity: O(N), N = length of given string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of str<=100

  ****/

//#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
using namespace std;

char* encode(char*);

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char str[10000];
		cin >> str;
		cout << encode(str) << endl;
	}
}

char *encode(char *src)
{
    if(!src) return src;

    int len = strlen(src);
    //char* dst = (char*)malloc(2*len+1);
    char* dst = new char[2*len+1];
    memset(dst, '\0', 2*len+1);

    char* t = dst;
    *t = *src;
    char* p = src;
    //t++;
    int cnt = 1;

    do
    {
        p = src;
        src++;
        if(*p == *src) cnt++;
        else {
            //char* num = itoa(cnt);
            //char* num = static_cast<char*>(cnt);
            stringstream ss;
            ss << cnt;
            const char* num = ss.str().c_str();
            strncat(dst, num, strlen(num));
            //cout << "num: " << num << endl;
            //cout << "dst: " << dst << endl;
            cnt = 1;
            t += strlen(num)+1;
            *t = *src;
        }
    } while(*src);

    return dst;
}



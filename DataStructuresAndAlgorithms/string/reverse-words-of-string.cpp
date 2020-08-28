/*************************
Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
*************************/
#include <iostream>
#include <string>
using namespace std;

void reverse_rec(string str, bool first)
{
    if(str.empty())
        return;
        
    int pos = str.find_first_of('.');
    if(pos < 0) {
        cout << str;
        if(first) cout << endl;
        return;
    }
        
    string s1 = str.substr(0, pos);
    string s2 = str.substr(pos+1);
    reverse_rec(s2, false);
    
    cout << "." << s1;
    if(first) cout << endl;
}
void reverse(string str)
{
    //cout << str << endl;
    int lastdot = str.find_last_of('.');
    //cout << lastdot << endl;
    string res = "";
    
    while(1) {
        if(lastdot < 0)
        {
            res += str;
            break;
        }
        string laststr = str.substr(lastdot+1);
        //cout << "laststr:" << laststr << endl;
        str = str.substr(0, lastdot);
        //cout << "str:" << str << endl;
        lastdot = str.find_last_of('.');
       
        res += laststr;
        res += ".";
    }
    cout << res << endl;
}

string reverseWords(string s)
{
    string res = "";
    int i = 0, j = -1;
    do
    {
        j++;
        if(s[j]=='.' || s[j]=='\0') {
            res = s.substr(i, j-i) + "." + res;
            //cout << "res: " << res << endl;
            i = j+1;
        }

    } while(j < s.length());
    res = res.substr(0, res.length()-1);
    return res;
}

int main() {
	//code
	int nT;
	string str;
	cin >> nT;
	while(nT--)
	{
	    cin >> str;
	    //reverse(str);
	    reverse_rec(str, true);
	}
	return 0;
}

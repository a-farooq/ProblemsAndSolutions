/****
Given a string of both uppercase and lowercase alphabets, the task is to print the string with alternate occurrences of any character dropped(including space and consider upper and lowercase as same).

Input:
First line consists of T test cases. First line of every test case consists of String S.

Output:
Single line output, print the updated string.

Constraints:
1<=T<=100
1<=|String|<=10000

Example:
Input:
2
It is a long day dear.
Geeks for geeks
Output:
It sa longdy ear.
Geks fore

Explanation:
For the 1st test case. 
Print first "I" and then ignore next "i". Similarly print first space then ignore next space. and so on.
  ****/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while(t--)
	{
	    short alp[26]={0};
	    short space=0;
	    string str;
	    //cin.ignore();
	    getline(cin, str);
	    //cout << str;
	    //cin.ignore();
	    for(auto ch : str) {
	        //cout << ch;
	        if(ch==' ') {
	            if(!space) cout << ch;
	            space = 1-space; //toggle from 0 to 1 and 1 to 0
	            //space = space^1; //toggle from 0 to 1 and 1 to 0
	        }
	        else {
	            //ch = tolower(ch);
	            if(!alp[tolower(ch)-'a']) cout << ch;
	            alp[tolower(ch)-'a']=1-alp[tolower(ch)-'a']; //toggle
	        }
	        //cin >> ch;
	    }
	    //cout << endl;
	    /*
	    char ch;
	    cin >> ch;
	    //ch = tolower(ch);
	    //alp[ch-'a']=1;
	    while(ch != '\n')
	    {
	        if(ch==' ') {
	            if(!space) cout << ch;
	            space = 1-space; //toggle from 0 to 1 and 1 to 0
	            //space = space^1; //toggle from 0 to 1 and 1 to 0
	        }
	        else {
	            ch = tolower(ch);
	            if(!alp[ch-'a']) cout << ch;
	            alp[ch-'a']=1-alp[ch-'a']; //toggle
	        }
	        cin >> ch;
	    }*/
	    cout << endl;
	}
	return 0;
}

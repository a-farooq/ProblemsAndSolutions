/****
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0
  ****/

#include <iostream>
#include <unordered_set>
using namespace std;

bool word_break(const unordered_set<string>& dict, string st, int i, int len)
{
    //cout << "=="<<i<<","<<len<<","<<st.substr(i,len) << endl;
    if(dict.find(st.substr(i,len))!=dict.end())
        return true;

    for(int k=1; k<=len-i; k++)
    {
		//find substring upto k
        if(dict.find(st.substr(i,k))!=dict.end())
        {
			//find substring k till end
            if(dict.find(st.substr(i+k,len-k-i))!=dict.end())
                return true;
            else {
                bool rv = word_break(dict, st, i+k, len);
                if(rv) return true;
            }
        }
    }
    return false;
    /*
    //if(i>=st.length())
    //    return false;

    cout << "=="<<i<<","<<j<<","<<st.substr(i,j) << endl;

    if(j==0 || (i+j <= st.length() && dict.find(st.substr(i,j))!=dict.end()))
        return true;

    if(j<st.length() && dict.find(st.substr(i,j))==dict.end())
        return false;

    bool lv=false, rv=false;

    for(int k=i+1; k<=j; k++)
    {
        cout << i << ","<<k<<","<<j<<endl;

        lv = word_break(dict, st, i, k);

        if(!lv) continue;

        rv = word_break(dict, st, i+k, j-k);

        if(lv & rv) return true;
    }

    return lv & rv;*/
}
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    unordered_set<string> dict;
	    cin >> n;
	    for(int i=0; i<n; i++) {
	        string st;
	        cin >> st;
	        dict.insert(st);
	    }

	    string st;
	    cin >> st;
	    bool ret = word_break(dict, st, 0, st.length());
	    cout << (ret?1:0) << endl;
	}
	return 0;
}

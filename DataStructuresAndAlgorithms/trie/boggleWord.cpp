/****
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

Solution:
Create a dictionary of given words using trie DS
Iterate over the matrix of chars recursively and search in dictionary for each char.
Print store the word in set if found in trie.
  ****/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct TrieNode
{
    bool leaf;
    TrieNode* child[26];

    TrieNode()
    {
        for(int i=0; i<26; i++) {
            child[i]=nullptr;
        }
        leaf = false;
    }
};

typedef vector<vector<char>> vec2d_char;
typedef vector<vector<bool>> vec2d_bool;

class Dictionary
{
    TrieNode* root;

public:

    Dictionary()
    {
        root = new TrieNode();
    }

    TrieNode* GetRoot() { return root; }

    void InsertWord(string st)
    {
        //cout << "insertWord"<<endl;
        if(!root) return;

        TrieNode* node = root;

        for(int i=0; i<st.length(); i++) {
            int k=toupper(st[i])-'A';
            //cout<<k << endl;

            if(!node->child[k]) {
                node->child[k]=new TrieNode();
            }
            node=node->child[k];
        }
        node->leaf = true;
    }

    bool SearchWord(string st)
    {
        if(!root) return false;

        for(int i=0; i<st.length(); i++) {
            char ch=toupper(st[i]);
            int k=ch-'A';

            if(!root->child[k]) {
                return false;
            }
            root=root->child[k];
        }
        return root->leaf;
    }

    void SearchBoggle(vec2d_char boggle, vec2d_bool vis, int i, int j, string st, TrieNode* root, set<string>& out)
    {
        int m=boggle.size();
        int n=boggle[0].size();
        //cout << i<<", "<<j<<", "<<m<<", "<<n<<endl;

        if(i<0 || i>=m || j<0 || j>=n || vis[i][j])
            return;

        char ch=boggle[i][j];
        st+=ch;
        //cout << ch << endl;

        int idx=toupper(ch)-'A';
        //cout << idx << endl;
        if(!root->child[idx]) return;

        root=root->child[idx];

        if(root->leaf) {
            //cout << "=="<<st << endl;
            out.insert(st);
            //return;
        }

        vis[i][j]= true;

        if(j+1<n && !vis[i][j+1]) {
            //st+=boggle[i][j+1];
            SearchBoggle(boggle, vis, i, j+1, st, root, out);
        }
        if(i+1<m && j+1<n && !vis[i+1][j+1]) {
            SearchBoggle(boggle, vis, i+1, j+1, st, root, out);
        }
        if(i+1<m && !vis[i+1][j])
            SearchBoggle(boggle, vis, i+1, j, st, root, out);
        if(i+1<m && j-1>=0 && !vis[i+1][j-1])
            SearchBoggle(boggle, vis, i+1, j-1, st, root, out);
        if(j-1>=0 && !vis[i][j-1])
            SearchBoggle(boggle, vis, i, j-1, st, root, out);
        if(i-1>=0 && j-1>=0 && !vis[i-1][j-1])
            SearchBoggle(boggle, vis, i-1, j-1, st, root, out);
        if(i-1>=0 && !vis[i-1][j])
            SearchBoggle(boggle, vis, i-1, j, st, root, out);
        if(i-1>=0 && j+1<n && !vis[i-1][j+1])
            SearchBoggle(boggle, vis, i-1, j+1, st, root, out);

    }
};

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m, n;
	    string st;
	    cin >> n;
	    //vector<string> dict;
	    Dictionary dict;


	    while(n--) {
	        cin >> st;
	        //dict.push_back(st);
	        dict.InsertWord(st);
	    }

	    cin >> m >> n;
	    //char boggle[m][n];
	    vec2d_char boggle(m,vector<char>(n));
	    vec2d_bool vis(m, vector<bool>(n, false));

	    for(int i=0; i<m; i++)
	        for(int j=0; j<n; j++)
	            cin >> boggle[i][j];

	    st="";
	    string out;
	    set<string> boggleSet;
	    //int i=0, j=0;
	    for(int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            //st+=boggle[i][j];
	            dict.SearchBoggle(boggle, vis, i, j, st, dict.GetRoot(), boggleSet);
	            //cout << "----"<<st<<endl;
	            //cout << st << endl;
	            st="";
	        }
	    }
	    if(!boggleSet.size())
	        cout << -1;
	    else
	        for(auto it : boggleSet)
	            cout << it << " ";

	    cout << endl;
	}
	return 0;
}

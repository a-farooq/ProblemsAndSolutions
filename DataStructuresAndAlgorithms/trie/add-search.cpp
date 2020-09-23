/****
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use the TRIE data structure and search the given string A. If found print 1 else 0.

Expected Time Complexity: O(N * WORD_LEN + A_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consists of three lines.
First line of each test case consist of a integer N, denoting the number of element in a Trie to be stored.
Second line of each test case consists of N space separated strings denoting the elements to be stored in the trie.
Third line of each test case consists of a String A to be searched in the stored elements.

Output:
Print the respective output in the respective line.

Constraints:
1<=T<=20
1<=N<=20

Example:
Input:
1
8
the a there answer any by bye their
the
Output:
1

  ****/

#include <iostream>
#include <vector>
using namespace std;

struct TrieNode
{
    bool leaf;
    //TrieNode* clist[26];
    vector<TrieNode*> clist;

    TrieNode() : leaf(false), clist(26, nullptr)
    {
    }
};

class Dictionary
{
    TrieNode* root;
public:
    Dictionary()
    {
        root = new TrieNode;
    }
    void add(string st)
    {
        TrieNode* node = root;
        for(int i=0; i<st.length(); i++) {
            int k=st[i]-'a';

            if(!node->clist[k]) {
                node->clist[k] = new TrieNode;
            }
            node = node->clist[k];
        }
        node->leaf = true;
    }
    bool search(string st)
    {
        TrieNode* node = root;
        for(int i=0; i<st.length(); i++) {
            int k=st[i]-'a';

            if(!node->clist[k]) {
                return false;
            }
            node = node->clist[k];
        }
        return node->leaf;
    }
};
int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    Dictionary dict;
	    int n;
	    cin >> n;
	    while(n--)
	    {
	        string st;
	        cin >> st;
	        dict.add(st);
	    }
	    string q;
	    cin >> q;
	    cout << (dict.search(q)?1:0) << endl;
	}
	return 0;
}

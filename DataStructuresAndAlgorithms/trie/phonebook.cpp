/*******
Given a list of contacts which exist in a phone directory and a query string str. The task is to implement search query for the phone directory. Run a search query for each prefix p of the query string str(i.e from  index 1 to str length) that prints all the distinct recommended contacts which have the same prefix as our query (p) in lexicographical order. Please refer the explanation part for better understanding.

NOTE: If there is no match between query and contacts , print "0".

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains three lines. First line of each test case contains N i.e., number of contacts. Second line contains space separated all the contacts in the form of string. And third line contains query string.

Output
For each test case, print each query result in new line. If there is no match between query and contacts, print "0".

Constraints:
1<=T<=100
1<=N<=50
1<=|contact[i].length|<=50
1<=|query length|<=6

Example:
Input:
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output:

geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0

============
4
10
abznehvggnuadsko abdnhtuydwvvh abqljekyiuvqajk abocnecsrlmnkp abhmtxfejjrhtldl abovqcafic abzqmnabyjprhuwqfnz abaclpshgwjnenlgdxtfa abpqjymhouwpswuelmntjy abpluvrsow
aboikd
14
saneadeb sanadcbabdcb sanbcaccd sanbded sanccdcdbd sancdcbeceaa sanadcadeee saneabddabcdea sanbaeecdecab sanbbeeaaa saneab sanaccccbcbedce sanbabdbaecba sancaa
sandde
1
geeks
geeksforgeeks
3
geeikistest geeksforgeeks geeksfortest
geeips
*******/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Node
{
    //int childCount;
    char data;
    string prefix;
    vector<Node*> clist;
    bool end;
public:
    Node() : data('-'), prefix(""), end(false)
    {
    }
    Node(char ch) : data(ch), prefix(""), end(false)
    {
    }
    void SetPrefix(string str) { prefix = str + data; }

    string GetPrefix() { return prefix; }

    vector<Node*> GetChildList() { return clist; }

    char GetData() { return data; }

    void AddChild(Node* node) { clist.push_back(node); }

    void SetEnd() { end = true; }

    bool IsEnd() { return end; }
};

class Phonebook
{
    Node* root;
    set<string> matchSet;

    void PrintMatches(Node* root)
    {
        if(root->IsEnd()) {
            //cout << root->GetPrefix() << " ";
            matchSet.insert(root->GetPrefix()); //output has to be sorted strings
            //return;
        }
        for(auto child : root->GetChildList()) {
            //cout << child->GetData();
            PrintMatches(child);
        }
    }
public:
    Phonebook()
    {
        root = new Node;
        matchSet.clear();
    }
    void AddContact(string name)
    {
        Node* cur = root;
        int i = 0;
        while(i < name.length()) {
            bool found = false;
            for(auto child : cur->GetChildList()) {
                if(child->GetData() == name[i]) {
                    cur = child;
                    found = true;
                    break;
                }
            }
            if(!found) {
                Node* node = new Node(name[i]);
                node->SetPrefix(cur->GetPrefix());
                cur->AddChild(node);
                cur = node;
            }
            i++;
        }
        cur->SetEnd();
    }
    void SearchContact(string name)
    {
        int i = 0;
        Node* cur = root;
        bool match = true;
        while(i < name.length()) {
            if(match) {
                match = false;
                for(auto child : cur->GetChildList()) {
                    if(child->GetData() == name[i]) {
                        //cout << child->GetPrefix();
                        PrintMatches(child);
                        for(auto match : matchSet)
                            cout << match << " ";
                        matchSet.clear();
                        cur = child;
                        match = true;
                        break;
                    }
                }
            }
            if(!match) cout << 0;
            cout << endl;
            i++;
        }
    }
};

int main() {
	//code
	int t, n;
	string str, query;
	cin >> t;
	while(t--) {
	    Phonebook pb;
	    cin >> n;
	    while(n--) {
	        cin >> str;
	        pb.AddContact(str);
	    }
	    cin >> query;
	    pb.SearchContact(query);
	}
	return 0;
}

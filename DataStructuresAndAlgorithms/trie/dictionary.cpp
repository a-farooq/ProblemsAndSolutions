/*******
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
    Node() : data('-'), prefix(""), end(false), clist(26)
    {
		for(auto i : clist) i = nullptr;
	}
    Node(char ch) : data(ch), prefix(""), end(false), clist(26)
    {
		for(auto i : clist) i = nullptr;
    }
    void SetPrefix(string str) { prefix = str; }

    string GetPrefix() { return prefix; }

    vector<Node*> & GetChildList() { return clist; }

	Node* GetNode(int idx) { return clist[idx-'a']; }

    char GetData() { return data; }

    void AddChild(Node* node, char ch) { clist[ch-'a'] = node; }

    void SetEnd() { end = true; }

    bool IsEnd() { return end; }
};

class Dictionary 
{
    Node* root;
public:
    Dictionary()
    {
        root = new Node;
    }
    void AddWord(string name)
    {
		//name = name.lower();
        Node* cur = root;
        for(char ch : name) {
			//vector<Node*> & clist = cur->GetChildList();
			Node* child = cur->GetNode(ch);// clist[ch-'a'];
            if(!child) {
                Node* node = new Node(ch);
                node->SetPrefix(cur->GetPrefix()+ch);
				//clist[ch-'a'] = node;
				cur->AddChild(node, ch);
                child = node;
            }
			cur = child;
        }
        cur->SetEnd();
    }
    bool SearchWord(string name)
    {
        Node* cur = root;
        for(char ch : name) 
		{
			Node* node = cur->GetNode(ch);
			if(!node) {
				return false;
			}
			cur = node;
        }
		if(!cur->IsEnd()) return false;
		return true;
    }
	void Print()
	{
		PrintUtil(root);
	}
private:
	void PrintUtil(Node* root) 
	{
		if(!root) return;

		if(root->IsEnd()) { cout << root->GetPrefix() << endl; }

		for(auto child : root->GetChildList())
		{
			PrintUtil(child);
		}
	}
};

int main() {
	int n;
	string str, query;
	Dictionary dict;
	cout << "Number of words: ";
	cin >> n;
	cout << "Input " << n << " words" << endl;
	while(n--) {
	    cin >> str;
	    dict.AddWord(str);
	}
	cout << "Printing dictionary..." << endl;
	dict.Print();
	cout << "Word to search: ";
	cin >> query;
	cout << (dict.SearchWord(query) ? "found" : "not found") << endl;
	return 0;
}

#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<cstdio>
#include<limits>
#include<vector>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct Node
{
public:
	string m_fname, m_lname;
	int m_age;

public:
	string tstr;
	Node(string fname, string lname, int age):m_fname(fname), m_lname(lname), m_age(age)
	{
		tstr = fname+lname+to_string(age);
	}
	Node(const Node& rhs)
	{
		this->m_fname = rhs.m_fname;
		this->m_lname = rhs.m_lname;
		this->m_age = rhs.m_age;
	}

	string GetFirstName() { return m_fname; }
	string GetLastName() { return m_lname; }
	int GetAge() { return m_age; }
};

class LRUCache
{
	int m_cap;
	typedef list<vector<Node*>>::iterator LRULISTITER;
	typedef unordered_map<string, list<vector<Node*>>::iterator> LRUHASH;

	list<vector<Node*>> lrulist;
	unordered_map<string, list<vector<Node*>>::iterator> lrumap;

	void refresh(LRULISTITER listiter)
	{
		cout << "inside refresh" << endl;
		if(lrulist.size() > 1) {
			//LRULISTITER temp;
			cout << "inside if" << endl;
			vector<Node*> vec;
			for(auto node : *listiter) {
				cout << node->m_fname << ", "<< node->m_lname << ", "<< node->m_age << endl;
				Node* newnode = new Node(node->m_fname, node->m_lname, node->m_age);
				//newnode->m_fname = node->m_fname;
				//newnode->m_lname = node->m_lname;
				//newnode->m_age = node->m_age;
				vec.push_back(newnode);
			}
			lrulist.push_front(vec);
			cout << listiter << ", "<< lrulist.begin() << endl;
			lrulist.erase(listiter);
			//lrulist.push_front(*listiter);
		}
	}
public:
	LRUCache(int capacity, string filename="") : m_cap(capacity)
	{
	
	}

	void add(string fname, string lname, int age)
	{
		cout << "inside add" << endl;
		
		auto mapiter = lrumap.find(fname);
		if(mapiter != lrumap.end()) { //found the first name (key) in cache (hash)
			cout << "if: " << fname << lname << age << endl;
			auto listiter = lrumap[fname]; //get the list iter
			
			string pstr = fname + lname + to_string(age); //form a temp string
			vector<Node*>& nodevec = *listiter; //get the list vector
			bool found = false;
			for(Node* node : nodevec) { //search temp str in the vector
				if(node->tstr == pstr) {
					found = true;
					break;
				}
			}
			if(!found) { //if not found, add new entry in vector
				Node* node = new Node(fname, lname, age);
				nodevec.push_back(node);
			}
			//renew the record in cache
			//auto temp = listiter;
			//lrulist.erase(temp);
			//lrulist.push_front(*listiter);
			refresh(listiter);
		}
		else {
			cout << "else:" << fname << lname << age << endl;
			Node* node = new Node(fname, lname, age);
			vector<Node*> vec;
			vec.push_back(node);
			//insert into list
			lrulist.push_front(vec);
			//insert into hash
			lrumap.emplace(fname, lrulist.begin());
			
			if(lrulist.size() > m_cap) { //cache is full
				//get lru item
				auto listiter = lrulist.rbegin();
				//get key for hash
				string fname = (*listiter).front()->GetFirstName();
				//remove from list and hash
				lrulist.pop_back();
				lrumap.erase(fname);
			}
		}
		cout << lrulist.size() << endl;
		cout << lrumap.size() << endl;
	}
	vector<Node*> search(string fname)
	{
		cout << "inside search: " << fname << endl;
		vector<Node*> vec;
		auto mapiter = lrumap.find(fname);
		if(mapiter != lrumap.end()) { //found in cache hash
			cout << "inside if:" << endl;
			auto listiter = lrumap[fname];
			
			//auto temp = listiter;
			//lrulist.erase(temp);
			//lrulist.push_front(*listiter);
			refresh(listiter);
			return *listiter;
		}
		cout << lrulist.size() << endl;
		cout << lrumap.size() << endl;
		return vec;
	}
	
	void clear() {
		for(auto listnode : lrulist) {
			for(auto vecnode : listnode) {
				delete vecnode;
			}
		}
	}
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string filename;
	LRUCache cache(3, filename);
	//read from file
	string fname, lname;
	int t, age;
	cache.add("aamil", "farooq", 30);
	cache.add("aamil", "far", 20);
	cache.add("main", "func", 40);
	cache.add("abab", "popo", 40);
	//cache.add("yuyu", "tyty", 40);
	/*
	cout << "Enter no of names: ";
	cin >> t;
	while(t--) {
		cout << "Enter first name, last name, age (name, name, age) to add : " << endl;
		cin >> fname >> lname >> age;
		cache.add(fname, lname, age);
	}
	cout << "Enter name to search: ";
	string query;
	cin >> query;
	*/
	vector<Node*> res = cache.search("aamil");
	for(auto node : res) {
		cout << node->GetFirstName() << ", " << node->GetLastName() << ", " << node->GetAge() << endl;
	}
	vector<Node*> res2 = cache.search("abab");
	for(auto node : res2) {
		cout << node->GetFirstName() << ", " << node->GetLastName() << ", " << node->GetAge() << endl;
	}
	return 0;
}


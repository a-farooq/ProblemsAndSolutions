//
//  main.cpp
//  Phonebook
//
//  Created by Aamil Farooq on 08/08/20.
//  Copyright © 2020 Aamil Farooq. All rights reserved.
//

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
            matchSet.insert(root->GetPrefix());
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

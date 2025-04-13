//
//  main.cpp
//  webapi-NASA
//
//  Created by Aamil Farooq on 11/08/20.
//  Copyright © 2020 Aamil Farooq. All rights reserved.
//

#include <iostream>
#include <vector>
#include <array>
//#include <cpprest/http_client.h>
//#include <cpprest/filestream.h>
//#include <cpprest/uri.h>
//#include <cpprest/json.h>

using namespace std;
void dfs(array<vector<bool>, 4> &vis)
{
    vis[0][0] = true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    array<vector<bool>, 4> vis;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++)
            vis[i].push_back(false);
        
    }
    /*
    for(auto i : vis) {
        vector<bool> vec(3, false);
        vis[i].push_back(vec);
        //vec.push_back(10);
        //cout << endl;
    }*/
    for(auto vec : vis) {
        for(auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "--------\n";
    dfs(vis);
    for(auto vec : vis) {
        for(auto i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

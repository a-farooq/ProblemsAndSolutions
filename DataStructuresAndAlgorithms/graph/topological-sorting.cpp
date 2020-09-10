/****
Given a Directed Graph. Find any Topological Sorting of that Graph.

Input:
The first line of input takes the number of test cases then T test cases follow . Each test case contains two lines. The first  line of each test case  contains two integers E and V representing no of edges and the number of vertices. Then in the next line are E  pairs of integers u, v representing an edge from u to v in the graph.

Output:
For each test case output will be 1 if the topological sort is done correctly else it will be 0.

Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort() which takes the adjacency list of the Graph and the number of vertices (N) as inputs are returns an array consisting of a the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 104
1 <= E <= (N*(N-1))/2
0 <= u, v <= N-1
Graph doesn't contain multiple edges, self loops and cycles.
Graph may be disconnected.

Example:
Input
2
6 6
5 0 5 2 2 3 4 0 4 1 1 3
3 4
3 0 1 0 2 0

Output:
1
1

Explanation:
Testcase 1: The output 1 denotes that the order is valid.  So, if you have implemented your function correctly, then output would be 1 for all test cases.

  ****/

// The Graph structure is as folows

void topoSorting(int u, vector<int> adj[], int vis[], vector<int>&out)
{
    vis[u]=1;
    //cout << "u: "<<u << endl;
    //for(auto val:adj[u]) cout << "=="<<val << " "; cout <<endl;
    //for(int v=0; v < adj[u].size(); v++) {
    for(auto v : adj[u]) {
        if(!vis[v]) {
            topoSorting(v, adj, vis, out);
        }
    }
    //cout << "--u: "<<u << endl;
    out.push_back(u);
}
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
vector<int> topoSort(int V, vector<int> adj[])
{
    // Your code here
    int visited[V] = {0};
    vector<int> vec;

    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            topoSorting(i, adj, visited, vec);
        }
    }

    //for(auto val : vec) cout << val << " "; cout <<endl;
    reverse(vec.begin(), vec.end());
    return vec;
}

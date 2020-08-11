/****
Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find the shortest distance of all the vertex's from the source vertex.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix and in the next line are V*V space-separated values, which denote the weight of an edge of the matrix (gr[i][j] represents the weight of an edge from ith node to jth node). The third line of each test case contains an integer denoting the source vertex s.

Output:
For each test, case output will be V space-separated integers where the ith integer denotes the shortest distance of the ith vertex from source vertex.

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra() which takes the adjacency matrix of the Graph g, the source vertex src and the number of vertices V as inputs and returns a list containing the minimum distance of all the vertices from the source vertex.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 20 
1 <= V <= 100
0 <= graph[i][j] <= 1000
0 <= s < V

Example:
Input:
2
2
0 25 25 0
0
3
0 1 43 1 0 6 43 6 0
2

Output:
0 25
7 6 0

Explanation:
Testcase 1: Shortest distance of source node 0 to 1 is 25, and shortest distance of source to source is 0.

Note:
You must assume that graph[i][j] = 0 means that the path from i to j does not exist.
****/
#include <iostream>
#include <vector>
using namespace std;

int min_dist_vertex(int dist[], bool spt[], int V)
{
    int min = INT_MAX;
    int ind;
    for(int i = 0; i < V; i++) {
        if(dist[i] < min && !spt[i]) {
            min = dist[i];
            ind = i;
        }
    }
    return ind;
}

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    // Your code here
    vector<int> res;

    int dist[V];
    fill_n(dist, V, INT_MAX);
    bool spt[V];
    fill_n(spt, V, false);

    dist[src] = 0;

    for(int i = 0; i < V-1; i++) {
        int u = min_dist_vertex(dist, spt, V);
        spt[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(g[u][v] && dist[u]+g[u][v] <= dist[v] && !spt[v]) {
                dist[v] = dist[u]+g[u][v];
            }
        }
    }

    //res.insert(res.end(), &dist[0], &dist[V]);
    copy(dist, dist+V, back_inserter(res));

    //lambda
    //for_each(res.begin(), res.end(), [](int&i) { cout << i << " "; } );
    //cout << endl;

    return res;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int V;
		cin >> V;
		vector<vector<int>> g(V);
		
		//for_each(g.begin(), g.end(), [](int&i){ } );
		for(int i = 0; i < V; i++) {
			vector<int> t(V);
			g[i] = t;
		}

		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
				cin >> g[i][j];

		int s;
		cin >> s;
		vector<int> res = dijkstra(g, s, V);
		for_each(res.begin(), res.end(), [](const int& i) { cout << i << " "; } );
		cout << endl;
	}
}

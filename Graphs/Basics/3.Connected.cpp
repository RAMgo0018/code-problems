/*Given a undirected Graph consisting of V vertices numbered from 0 to V-1 and E edges. The ith edge is represented by [ai,bi], denoting a edge between vertex ai and bi. We say two vertices u and v belong to a same component if there is a path from u to v or v to u. Find the number of connected components in the graph.



A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.


Example 1



Input: V=4, edges=[[0,1],[1,2]]

Output: 2

Explanation: Vertices {0,1,2} forms the first component and vertex 3 forms the second component.*/#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to convert edge list to adjacency list
    vector<vector<int>> convertEdgeListToAdj(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);   // undirected graph
        }

        return adj;
    }

    // DFS helper
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        // Step 1: Convert edges to adjacency list
        vector<vector<int>> adj = convertEdgeListToAdj(V, edges);

        // Step 2: Count connected components
        vector<int> visited(V, 0);
        int count = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }

        return count;
    }
};

int main() {
    int V, E;
    cin >> V >> E;   // number of vertices and edges

    vector<vector<int>> edges(E, vector<int>(2));
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj;
    cout << obj.findNumberOfComponent(V, edges);

    return 0;
}

/*Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void helper(vector<vector<int>>& adj, vector<int>& dfsAns, vector<int>& visited, int node)
    {
        visited[node] = 1;
        dfsAns.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])   // important check
                helper(adj, dfsAns, visited, it);
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> dfsAns;
        vector<int> visited(adj.size(), 0);

        helper(adj, dfsAns, visited, 0);

        return dfsAns;
    }
};

int main() {
    int V, E;
    cin >> V >> E;   // number of vertices and edges

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    Solution obj;
    vector<int> result = obj.dfs(adj);

    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}

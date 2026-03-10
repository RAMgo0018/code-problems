/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Note: The graph can have multiple component.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    bool bfs(int start, vector<vector<int>> &adj, vector<int> &visited) // BFS function to detect cycle
    {
        queue<pair<int,int>> q; // queue storing {node, parent}

        visited[start] = 1; // mark starting node visited
        q.push({start, -1}); // push start node with parent -1

        while(!q.empty()) // BFS traversal
        {
            int node = q.front().first; // current node
            int parent = q.front().second; // parent of current node
            q.pop(); // remove from queue

            for(auto adjnode : adj[node]) // traverse adjacent nodes
            {
                if(!visited[adjnode]) // if not visited
                {
                    visited[adjnode] = 1; // mark visited
                    q.push({adjnode, node}); // push with current node as parent
                }
                else if(adjnode != parent) // visited but not parent -> cycle exists
                {
                    return true; // cycle detected
                }
            }
        }

        return false; // no cycle found in this component
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) { // function to check cycle in graph
        
        vector<vector<int>> adj(V); // adjacency list

        for(auto e : edges) // convert edge list to adjacency list
        {
            int u = e[0]; // first node
            int v = e[1]; // second node

            adj[u].push_back(v); // add edge u -> v
            adj[v].push_back(u); // add edge v -> u (undirected graph)
        }

        vector<int> visited(V,0); // visited array

        for(int i = 0; i < V; i++) // check for all components
        {
            if(!visited[i]) // if node not visited
            {
                if(bfs(i, adj, visited)) // run BFS
                    return true; // cycle found
            }
        }

        return false; // no cycle in graph
    }
};

int main()
{
    int V, E; // number of vertices and edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2)); // edge list

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) // input edges
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution obj; // create object
    bool ans = obj.isCycle(V, edges); // call function

    if(ans)
        cout << "Cycle detected in graph\n"; // print if cycle exists
    else
        cout << "No cycle in graph\n"; // print if no cycle

    return 0; // end program
}
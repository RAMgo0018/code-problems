#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited) // DFS function to detect cycle
    {
        visited[node] = 1; // mark current node visited

        for(auto it : adj[node]) // traverse all adjacent nodes
        {
            if(!visited[it]) // if adjacent node not visited
            {
                if(dfs(it, node, adj, visited)) // recursive DFS call
                    return true; // cycle found
            }
            else if(it != parent) // if visited and not parent
            {
                return true; // cycle detected
            }
        }

        return false; // no cycle found in this path
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) { // function to check cycle
        
        vector<vector<int>> adj(V); // adjacency list

        for(auto e : edges) // convert edge list to adjacency list
        {
            int u = e[0]; // first vertex
            int v = e[1]; // second vertex

            adj[u].push_back(v); // add edge u -> v
            adj[v].push_back(u); // add edge v -> u (undirected)
        }

        vector<int> visited(V, 0); // visited array

        for(int i = 0; i < V; i++) // check all components
        {
            if(!visited[i]) // if node not visited
            {
                if(dfs(i, -1, adj, visited)) // start DFS
                    return true; // cycle found
            }
        }

        return false; // no cycle in graph
    }
};

int main()
{
    int V, E; // vertices and edges
    cout<<"Enter number of vertices and edges: ";
    cin>>V>>E;

    vector<vector<int>> edges(E, vector<int>(2)); // edge list

    cout<<"Enter edges (u v):\n";
    for(int i=0;i<E;i++) // input edges
    {
        cin>>edges[i][0]>>edges[i][1];
    }

    Solution obj; // create object
    bool ans = obj.isCycle(V, edges); // call function

    if(ans)
        cout<<"Cycle detected in graph"<<endl; // print if cycle exists
    else
        cout<<"No cycle in graph"<<endl; // print if no cycle

    return 0; // program end
}
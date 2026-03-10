/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int> &color)
    {
        color[node] = col; // assign color to current node

        for(auto it : graph[node]) // traverse all neighbours
        {
            if(color[it] == -1) // if neighbour not colored
            {
                if(dfs(it, !col, graph, color) == false) // color neighbour with opposite color
                    return false; // graph not bipartite
            }

            else if(color[it] == col) // if neighbour has same color
            {
                return false; // not bipartite
            }
        }

        return true; // valid coloring
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int V = graph.size(); // number of vertices
        vector<int> color(V, -1); // initialize all nodes with no color

        for(int i = 0; i < V; i++) // check every component
        {
            if(color[i] == -1) // if node not colored
            {
                if(dfs(i, 0, graph, color) == false) // start DFS coloring
                    return false; // not bipartite
            }
        }

        return true; // graph is bipartite
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V; // input vertices

    cout << "Enter number of edges: ";
    cin >> E; // input edges

    vector<vector<int>> graph(V); // adjacency list

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v; // input edge
        graph[u].push_back(v); // add edge u->v
        graph[v].push_back(u); // add edge v->u (undirected graph)
    }

    Solution obj; // create object
    bool result = obj.isBipartite(graph); // call function

    if(result)
        cout << "Graph is Bipartite\n"; // print result
    else
        cout << "Graph is NOT Bipartite\n"; // print result

    return 0; // end program
}
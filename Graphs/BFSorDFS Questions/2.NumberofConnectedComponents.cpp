/*Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& component) {
        visited[node] = 1; // mark node as visited
        component.push_back(node); // add node to current component

        for(auto it : adj[node]) { // traverse all neighbours
            if(!visited[it]) { // if neighbour not visited
                dfs(it, adj, visited, component); // call DFS recursively
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V); // adjacency list

        for(auto e : edges) { // iterate over edges
            int u = e[0]; // first node
            int v = e[1]; // second node

            adj[u].push_back(v); // add edge u -> v
            adj[v].push_back(u); // add edge v -> u because graph is undirected
        }

        vector<vector<int>> components; // store all components
        vector<int> visited(V, 0); // visited array

        for(int i = 0; i < V; i++) { // traverse all vertices
            if(!visited[i]) { // if vertex not visited

                vector<int> component; // store current component
                dfs(i, adj, visited, component); // perform DFS

                components.push_back(component); // store component
            }
        }

        return components; // return all components
    }
};

int main() {

    int V, E; 
    cout << "Enter number of vertices: ";
    cin >> V; // input number of vertices

    cout << "Enter number of edges: ";
    cin >> E; // input number of edges

    vector<vector<int>> edges; // store edges

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v; // input edge
        edges.push_back({u, v}); // store edge
    }

    Solution obj; // create object of Solution class

    vector<vector<int>> components = obj.getComponents(V, edges); // get components

    cout << "\nConnected Components:\n";
    for(int i = 0; i < components.size(); i++) { // iterate components
        cout << "Component " << i + 1 << ": ";
        for(auto node : components[i]) { // print nodes in component
            cout << node << " ";
        }
        cout << endl;
    }

    return 0; // end program
}
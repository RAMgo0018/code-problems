#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;

    int m;
    cout << "Enter Number of Edges: ";
    cin >> m;

    // Adjacency List
    vector<vector<int>> adj(n);

    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // remove this if graph is directed
    }

    // Print adjacency list
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for(int x : adj[i])
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

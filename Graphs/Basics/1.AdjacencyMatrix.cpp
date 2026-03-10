#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;

    int m;
    cout << "Enter Number of Edges: ";
    cin >> m;

    // create n x n matrix initialized with 0
    vector<vector<int>> adj(n, vector<int>(n, 0));

    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;   // because undirected graph
    }

    // Print matrix
    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    return 0;
}

/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to convert adjacency matrix to adjacency list
    vector<vector<int>> convertMatrixToList(vector<vector<int>>& matrix) {

        int n = matrix.size();                 // number of nodes
        vector<vector<int>> adjList(n);        // adjacency list

        // Traverse the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                // If there is a connection and it is not a self loop
                if(matrix[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);   // add edge i -> j
                }
            }
        }

        return adjList;
    }

    // DFS function to visit all nodes in a component
    void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {

        visited[node] = 1;  // mark current node as visited

        // Traverse all neighbours of current node
        for(auto it : adjList[node]) {

            // If neighbour is not visited, visit it
            if(!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

    // Function to count number of provinces (connected components)
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        // Step 1: Convert adjacency matrix to adjacency list
        vector<vector<int>> adjList = convertMatrixToList(isConnected);

        // Step 2: Visited array to keep track of visited nodes
        vector<int> visited(n, 0);

        int count = 0;   // number of connected components

        // Traverse all nodes
        for(int i = 0; i < n; i++) {

            // If node not visited, start DFS
            if(!visited[i]) {
                dfs(i, adjList, visited);
                count++;                // one component found
            }
        }

        return count;
    }
};

int main() {

    Solution obj;

    int n;

    // Input number of cities (nodes)
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input adjacency matrix
    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find number of provinces
    int result = obj.findCircleNum(matrix);

    cout << "Number of Provinces (Connected Components): " << result << endl;

    return 0;
}
/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size(); // number of rows
        int m = mat[0].size(); // number of columns

        vector<vector<int>> distance(n, vector<int>(m, 0)); // matrix to store distance from nearest 0
        vector<vector<int>> visited(n, vector<int>(m, 0)); // visited matrix

        queue<pair<pair<int,int>,int>> q; // queue storing {{row,col},steps}

        int drow[] = {-1,0,1,0}; // row movement directions
        int dcol[] = {0,1,0,-1}; // column movement directions

        for(int i=0;i<n;i++) // traverse matrix
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0) // if cell contains 0
                {
                    visited[i][j]=1; // mark visited
                    q.push({{i,j},0}); // push into queue with distance 0
                }
            }
        }

        while(!q.empty()) // BFS traversal
        {
            int row = q.front().first.first; // current row
            int col = q.front().first.second; // current column
            int steps = q.front().second; // current distance
            q.pop(); // remove element from queue

            distance[row][col] = steps; // store distance

            for(int i=0;i<4;i++) // check all 4 directions
            {
                int nrow = row + drow[i]; // neighbour row
                int ncol = col + dcol[i]; // neighbour column

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0) // valid cell and not visited
                {
                    visited[nrow][ncol] = 1; // mark neighbour visited
                    q.push({{nrow,ncol},steps+1}); // push neighbour with distance+1
                }
            }
        }

        return distance; // return final distance matrix
    }
};

int main()
{
    int n,m; // rows and columns
    cout<<"Enter rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> mat(n, vector<int>(m)); // create matrix

    cout<<"Enter matrix values (0 or 1):\n";
    for(int i=0;i<n;i++) // input matrix
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    Solution obj; // create object
    vector<vector<int>> ans = obj.updateMatrix(mat); // call function

    cout<<"Distance Matrix:\n";
    for(int i=0;i<n;i++) // print result
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0; // end program
}
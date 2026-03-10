/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        queue<pair<pair<int,int>,int>> q; // queue to store {{row,col},time}
        vector<vector<int>> visited(n, vector<int>(m,0)); // visited matrix

        int fresh = 0; // count of fresh oranges

        for(int i=0;i<n;i++){ // traverse grid
            for(int j=0;j<m;j++){

                if(grid[i][j]==2){ // if rotten orange
                    q.push({{i,j},0}); // push into queue with time 0
                    visited[i][j]=2; // mark visited
                }

                if(grid[i][j]==1) fresh++; // count fresh oranges
            }
        }

        int drow[] = {-1,0,1,0}; // direction array for rows
        int dcol[] = {0,1,0,-1}; // direction array for columns

        int time = 0; // maximum time required
        int cnt = 0; // count of oranges that became rotten

        while(!q.empty()){ // BFS traversal

            int r = q.front().first.first; // current row
            int c = q.front().first.second; // current column
            int t = q.front().second; // current time
            q.pop(); // remove from queue

            time = max(time,t); // update maximum time

            for(int i=0;i<4;i++){ // check all 4 directions

                int nrow = r + drow[i]; // neighbour row
                int ncol = c + dcol[i]; // neighbour column

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && // check boundaries
                   visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){ // check fresh orange

                    q.push({{nrow,ncol},t+1}); // push neighbour with time+1
                    visited[nrow][ncol]=2; // mark as rotten
                    cnt++; // increase rotten count
                }
            }
        }

        if(cnt != fresh) return -1; // if all fresh oranges not rotten

        return time; // return total time
    }
};

int main(){

    int n,m; // rows and columns
    cout<<"Enter number of rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m)); // create grid

    cout<<"Enter grid values (0 empty, 1 fresh, 2 rotten):"<<endl;
    for(int i=0;i<n;i++){ // input grid
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    Solution obj; // create object of Solution class
    int ans = obj.orangesRotting(grid); // call function

    cout<<"Minimum time required to rot all oranges: "<<ans<<endl; // print result

    return 0; // program end
}
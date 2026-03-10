/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1*/
#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid) {

        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        queue<pair<int,int>> q; // queue for BFS
        vis[row][col] = 1; // mark starting cell visited
        q.push({row, col}); // push starting cell

        int delrow[] = {-1, 0, 1, 0}; // row movement (up, right, down, left)
        int delcol[] = {0, 1, 0, -1}; // column movement

        while(!q.empty()) {

            int r = q.front().first; // current row
            int c = q.front().second; // current column
            q.pop(); // remove element from queue

            for(int i = 0; i < 4; i++) { // explore all 4 directions

                int nrow = r + delrow[i]; // compute new row
                int ncol = c + delcol[i]; // compute new column

                if(nrow >= 0 && nrow < n &&   // check row boundary
                   ncol >= 0 && ncol < m &&   // check column boundary
                   !vis[nrow][ncol] &&        // check not visited
                   grid[nrow][ncol] == '1') { // check land

                    vis[nrow][ncol] = 1; // mark visited
                    q.push({nrow, ncol}); // push into queue
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        vector<vector<int>> vis(n, vector<int>(m, 0)); // visited matrix

        int cnt = 0; // island counter

        for(int row = 0; row < n; row++) { // traverse rows
            for(int col = 0; col < m; col++) { // traverse columns

                if(!vis[row][col] && grid[row][col] == '1') { // unvisited land
                    cnt++; // new island found
                    bfs(row, col, vis, grid); // perform BFS
                }
            }
        }

        return cnt; // return number of islands
    }
};

int main() {

    int n, m;
    cout << "Enter number of rows: ";
    cin >> n; // input rows

    cout << "Enter number of columns: ";
    cin >> m; // input columns

    vector<vector<char>> grid(n, vector<char>(m)); // create grid

    cout << "Enter grid values (0 for water, 1 for land):\n";
    for(int i = 0; i < n; i++) { // input grid
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj; // create solution object
    int result = obj.numIslands(grid); // call function

    cout << "\nNumber of Islands: " << result << endl; // print result

    return 0; // end program
}
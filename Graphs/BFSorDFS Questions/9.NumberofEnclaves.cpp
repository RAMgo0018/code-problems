/*You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col) {

        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        visited[row][col] = 1; // mark current cell visited

        vector<int> delrow = {-1, 0, 1, 0}; // row directions (up, right, down, left)
        vector<int> delcol = {0, 1, 0, -1}; // column directions

        for(int i = 0; i < 4; i++) { // explore all 4 directions

            int newrow = row + delrow[i]; // compute new row
            int newcol = col + delcol[i]; // compute new column

            if(newrow >= 0 && newrow < n &&     // check row boundary
               newcol >= 0 && newcol < m &&     // check column boundary
               grid[newrow][newcol] == 1 &&     // check land cell
               !visited[newrow][newcol]) {      // check if not visited

                dfs(grid, visited, newrow, newcol); // recursive DFS
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size(); // number of rows
        int m = grid[0].size(); // number of columns

        vector<vector<int>> visited(n, vector<int>(m, 0)); // visited matrix

        for(int j = 0; j < m; j++) { // traverse first and last row

            if(!visited[0][j] && grid[0][j] == 1) // first row land
                dfs(grid, visited, 0, j); // DFS from boundary

            if(!visited[n-1][j] && grid[n-1][j] == 1) // last row land
                dfs(grid, visited, n-1, j); // DFS from boundary
        }

        for(int i = 0; i < n; i++) { // traverse first and last column

            if(!visited[i][0] && grid[i][0] == 1) // first column land
                dfs(grid, visited, i, 0); // DFS from boundary

            if(!visited[i][m-1] && grid[i][m-1] == 1) // last column land
                dfs(grid, visited, i, m-1); // DFS from boundary
        }

        int count = 0; // count enclaves

        for(int i = 0; i < n; i++) { // traverse grid
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !visited[i][j]) // land not connected to boundary
                    count++; // increase enclave count
            }
        }

        return count; // return total enclaves
    }
};

int main() {

    int n, m;
    cout << "Enter number of rows: ";
    cin >> n; // input rows

    cout << "Enter number of columns: ";
    cin >> m; // input columns

    vector<vector<int>> grid(n, vector<int>(m)); // create grid

    cout << "Enter grid values (0 for water, 1 for land):\n";
    for(int i = 0; i < n; i++) { // input grid
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj; // create object of Solution class
    int result = obj.numEnclaves(grid); // call function

    cout << "\nNumber of Enclave Land Cells: " << result << endl; // print result

    return 0; // end program
}
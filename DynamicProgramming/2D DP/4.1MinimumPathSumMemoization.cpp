/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) { // recursive helper to find minimum path sum to cell (i, j)
        if(i == 0 && j == 0) return grid[0][0];                                    // base case: starting cell cost
        if(i < 0 || j < 0) return 1e9;                                             // out of bounds returns large value

        if(dp[i][j] != -1) return dp[i][j];                                       // return stored value if already computed

        int left = grid[i][j] + helper(grid, dp, i, j-1);                          // path sum coming from left cell
        int up   = grid[i][j] + helper(grid, dp, i-1, j);                          // path sum coming from upper cell

        return dp[i][j] = min(left, up);                                          // store and return minimum of both paths
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();                                                       // number of rows
        int m = grid[0].size();                                                    // number of columns

        vector<vector<int>> dp(n, vector<int>(m, -1));                            // dp table initialized with -1

        return helper(grid, dp, n-1, m-1);                                         // compute minimum path sum to bottom-right cell
    }
};

int main() {
    int n, m;                                                                      // variables for grid size
    cin >> n >> m;                                                                // input number of rows and columns

    vector<vector<int>> grid(n, vector<int>(m));                                  // grid to store values
    for(int i = 0; i < n; i++) {                                                   // loop over rows
        for(int j = 0; j < m; j++) {                                               // loop over columns
            cin >> grid[i][j];                                                     // input grid value
        }
    }

    Solution obj;                                                                 // create Solution object
    cout << obj.minPathSum(grid);                                                  // print minimum path sum

    return 0;                                                                     // end of program
}

/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();                                     // number of rows
        int m = grid[0].size();                                  // number of columns

        vector<vector<int>> dp(n, vector<int>(m, 0));            // dp table to store minimum path sum

        for(int i = 0; i < n; i++) {                             // loop over rows
            for(int j = 0; j < m; j++) {                         // loop over columns

                if(i == 0 && j == 0) {                           // base case: starting cell
                    dp[i][j] = grid[0][0];                       // path sum equals starting cell value
                }
                else {
                    int l = 1e9, r = 1e9;                        // large values for left and up paths

                    if(j > 0) l = grid[i][j] + dp[i][j-1];       // path sum coming from left cell
                    if(i > 0) r = grid[i][j] + dp[i-1][j];       // path sum coming from upper cell

                    dp[i][j] = min(l, r);                        // store minimum of both paths
                }
            }
        }

        return dp[n-1][m-1];                                     // return minimum path sum to bottom-right cell
    }
};

int main() {
    int n, m;                                                    // variables for grid size
    cin >> n >> m;                                              // input number of rows and columns

    vector<vector<int>> grid(n, vector<int>(m));                // grid to store values
    for(int i = 0; i < n; i++) {                                // loop over rows
        for(int j = 0; j < m; j++) {                            // loop over columns
            cin >> grid[i][j];                                  // input grid value
        }
    }

    Solution obj;                                               // create Solution object
    cout << obj.minPathSum(grid);                               // print minimum path sum

    return 0;                                                   // end of program
}

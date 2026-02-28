#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();                              // number of rows
        int n = obstacleGrid[0].size();                           // number of columns
        vector<vector<int>> dp(m, vector<int>(n, 0));             // dp table to store number of paths

        dp[0][0] = 1;                                             // starting cell has one path

        for(int i = 0; i < m; i++) {                              // loop over rows
            for(int j = 0; j < n; j++) {                          // loop over columns
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;         // if obstacle, no path to this cell
                else if(i == 0 && j == 0) continue;               // skip starting cell
                else {
                    int up = 0, left = 0;                         // variables to store paths from top and left

                    if(i > 0) up = dp[i-1][j];                    // get paths from upper cell
                    if(j > 0) left = dp[i][j-1];                  // get paths from left cell

                    dp[i][j] = up + left;                         // total paths to current cell
                }
            }
        }

        return dp[m-1][n-1];                                      // return paths to bottom-right cell
    }
};

int main() {
    int m, n;                                                     // variables for grid size
    cin >> m >> n;                                               // input number of rows and columns

    vector<vector<int>> obstacleGrid(m, vector<int>(n));         // grid to store obstacles
    for(int i = 0; i < m; i++) {                                 // loop over rows
        for(int j = 0; j < n; j++) {                             // loop over columns
            cin >> obstacleGrid[i][j];                           // input grid value (0 or 1)
        }
    }

    Solution obj;                                                // create Solution object
    cout << obj.uniquePathsWithObstacles(obstacleGrid);          // print number of unique paths

    return 0;                                                    // end of program
}

/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));   // dp table to store number of paths for each cell

        dp[0][0] = 1;                                   // starting cell has exactly one path

        for(int i = 0; i < m; i++) {                    // loop over rows
            for(int j = 0; j < n; j++) {                // loop over columns
                if(i == 0 && j == 0) continue;          // skip starting cell

                int up = 0, left = 0;                   // variables to store paths from top and left

                if(i > 0) up = dp[i-1][j];              // get paths from top cell if exists
                if(j > 0) left = dp[i][j-1];            // get paths from left cell if exists

                dp[i][j] = up + left;                   // total paths to current cell
            }
        }

        return dp[m-1][n-1];                            // return paths to bottom-right cell
    }
};

int main() {
    int m = 3, n = 7;                                   // grid size (rows = m, columns = n)

    Solution obj;                                       // create object of Solution class
    int result = obj.uniquePaths(m, n);                 // call uniquePaths function

    cout << "Number of unique paths: " << result;       // print result

    return 0;                                           // end of program
}

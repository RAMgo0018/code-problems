/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int i, int j, vector<vector<int>>& dp) {        // recursive helper to count paths to cell (i, j)
        if(i == 0 && j == 0) return 1;                          // base case: start cell has one path
        if(i < 0 || j < 0) return 0;                            // out of grid means no path

        if(dp[i][j] != -1) return dp[i][j];                    // return stored value if already computed

        int up = helper(i-1, j, dp);                            // count paths from top cell
        int left = helper(i, j-1, dp);                          // count paths from left cell

        return dp[i][j] = up + left;                            // store and return total paths
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));         // dp table initialized with -1
        return helper(m-1, n-1, dp);                            // compute paths to bottom-right cell
    }
};

int main() {
    int m = 3, n = 7;                                          // grid size (rows = m, columns = n)

    Solution obj;                                              // create object of Solution class
    int result = obj.uniquePaths(m, n);                        // call uniquePaths function

    cout << "Number of unique paths: " << result;              // print result

    return 0;                                                  // end of program
}


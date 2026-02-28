#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp, int n, int m) { // recursive helper to find max path to cell (i, j)
        if(j < 0 || j >= m) return -1e9;                                                          // out of column bounds returns large negative
        if(i == 0) return mat[0][j];                                                             // base case: first row value

        if(dp[i][j] != -1) return dp[i][j];                                                     // return stored value if already computed

        int u   = mat[i][j] + helper(i-1, j,   mat, dp, n, m);                                   // path sum coming from up
        int dd  = mat[i][j] + helper(i-1, j-1, mat, dp, n, m);                                   // path sum coming from up-left
        int dup = mat[i][j] + helper(i-1, j+1, mat, dp, n, m);                                   // path sum coming from up-right

        return dp[i][j] = max(u, max(dd, dup));                                                  // store and return maximum of three paths
    }

public:
    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size();                                                                     // number of rows
        int m = mat[0].size();                                                                  // number of columns

        vector<vector<int>> dp(n, vector<int>(m, -1));                                          // dp table initialized with -1

        int ans = -1e9;                                                                         // variable to store final answer

        for(int j = 0; j < m; j++) {                                                            // loop over last row columns
            ans = max(ans, helper(n-1, j, mat, dp, n, m));                                      // compute max path ending at each column
        }

        return ans;                                                                             // return maximum path sum
    }
};

int main() {
    int n, m;                                                                                   // variables for matrix size
    cin >> n >> m;                                                                             // input number of rows and columns

    vector<vector<int>> mat(n, vector<int>(m));                                                 // matrix to store values
    for(int i = 0; i < n; i++) {                                                               // loop over rows
        for(int j = 0; j < m; j++) {                                                           // loop over columns
            cin >> mat[i][j];                                                                  // input matrix value
        }
    }

    Solution obj;                                                                              // create Solution object
    cout << obj.maximumPath(mat);                                                              // print maximum path sum

    return 0;                                                                                  // end of program
}

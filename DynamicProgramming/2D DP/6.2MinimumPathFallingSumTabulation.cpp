#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) {
        int n = mat.size();                                      // number of rows
        int m = mat[0].size();                                   // number of columns

        vector<vector<int>> dp(n, vector<int>(m, -1));           // dp table to store maximum path sums

        for(int j = 0; j < m; j++)                               // initialize first row
        {
            dp[0][j] = mat[0][j];                                // first row path sum equals matrix values
        }

        for(int i = 1; i < n; i++)                               // loop over rows from second row
        {
            for(int j = 0; j < m; j++)                           // loop over columns
            {
                int u = mat[i][j] + dp[i-1][j];                  // path sum coming from up

                int ul = -1e9;                                   // large negative for up-left
                if(j > 0) ul = mat[i][j] + dp[i-1][j-1];         // path sum coming from up-left

                int ur = -1e9;                                   // large negative for up-right
                if(j < m-1) ur = mat[i][j] + dp[i-1][j+1];       // path sum coming from up-right

                dp[i][j] = max(u, max(ul, ur));                  // store maximum of three paths
            }
        }

        int maxi = dp[n-1][0];                                   // initialize maximum from last row
        for(int j = 1; j < m; j++)                               // loop over last row
        {
            maxi = max(maxi, dp[n-1][j]);                        // update maximum
        }

        return maxi;                                             // return maximum path sum
    }
};

int main() {
    int n, m;                                                    // variables for matrix size
    cin >> n >> m;                                              // input number of rows and columns

    vector<vector<int>> mat(n, vector<int>(m));                 // matrix to store values
    for(int i = 0; i < n; i++) {                                // loop over rows
        for(int j = 0; j < m; j++) {                            // loop over columns
            cin >> mat[i][j];                                   // input matrix value
        }
    }

    Solution obj;                                               // create Solution object
    cout << obj.maximumPath(mat);                               // print maximum path sum

    return 0;                                                   // end of program
}


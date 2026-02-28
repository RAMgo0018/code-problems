/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();                                  // number of rows in triangle
        int m = triangle[n-1].size();                            // size of last row

        vector<vector<int>> dp(n, vector<int>(m, 0));            // dp table to store minimum path sums

        for(int j = 0; j < m; j++)                               // loop over last row
        {
            dp[n-1][j] = triangle[n-1][j];                       // initialize dp with last row values
        }

        for(int i = n-2; i >= 0; i--)                            // loop from second last row to top
        {
            for(int j = i; j >= 0; j--)                          // loop over elements in current row
            {
                int l = triangle[i][j] + dp[i+1][j];             // path sum from left-down
                int r = triangle[i][j] + dp[i+1][j+1];           // path sum from right-down
                dp[i][j] = min(l, r);                            // store minimum of both
            }
        }

        return dp[0][0];                                         // return minimum path sum from top to bottom
    }
};

int main() {
    int n;                                                       // variable for number of rows
    cin >> n;                                                   // input number of rows

    vector<vector<int>> triangle(n);                            // triangle to store input
    for(int i = 0; i < n; i++) {                                // loop over rows
        triangle[i].resize(i+1);                                // resize each row to i+1 elements
        for(int j = 0; j <= i; j++) {                           // loop over elements in row
            cin >> triangle[i][j];                              // input triangle value
        }
    }

    Solution obj;                                               // create Solution object
    cout << obj.minimumTotal(triangle);                         // print minimum path sum

    return 0;                                                   // end of program
}

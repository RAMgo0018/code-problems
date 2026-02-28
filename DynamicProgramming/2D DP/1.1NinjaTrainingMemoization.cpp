/*A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.



Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.


Example 1

Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]

Output: 210

Explanation:

Day 1: fighting practice = 70

Day 2: stealth training = 50

Day 3: fighting practice = 90

Total = 70 + 50 + 90 = 210

This gives the optimal points.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(int ind, int last, vector<vector<int>>& matrix, vector<vector<int>>& dp) { // recursive helper with memoization
        if(ind == 0) {                                                                    // base case: day 0
            int maxi = 0;                                                                // variable to store maximum points
            for(int i = 0; i < 3; i++) {                                                  // try all 3 tasks
                if(i != last)                                                            // skip task done on previous day
                    maxi = max(maxi, matrix[0][i]);                                      // take maximum
            }
            return dp[0][last] = maxi;                                                    // store and return result
        }

        if(dp[ind][last] != -1) return dp[ind][last];                                    // return if already computed

        int maxi = 0;                                                                    // variable to store maximum points
        for(int i = 0; i < 3; i++) {                                                      // try all 3 tasks for today
            if(i != last) {                                                              // skip same task as yesterday
                int points = matrix[ind][i] + helper(ind - 1, i, matrix, dp);            // today points + best till yesterday
                maxi = max(maxi, points);                                                // update maximum
            }
        }

        return dp[ind][last] = maxi;                                                     // store and return result
    }

public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();                                                           // number of days
        vector<vector<int>> dp(n, vector<int>(4, -1));                                   // dp table: dp[day][last_task]
        return helper(n - 1, 3, matrix, dp);                                             // start from last day with no last task
    }
};

int main() {
    int n;                                                                              // variable for number of days
    cin >> n;                                                                          // input number of days

    vector<vector<int>> matrix(n, vector<int>(3));                                     // matrix to store task points
    for(int i = 0; i < n; i++) {                                                       // loop over days
        for(int j = 0; j < 3; j++) {                                                   // loop over tasks
            cin >> matrix[i][j];                                                       // input task points
        }
    }

    Solution obj;                                                                      // create Solution object
    cout << obj.ninjaTraining(matrix);                                                 // print maximum points

    return 0;                                                                          // end of program
}



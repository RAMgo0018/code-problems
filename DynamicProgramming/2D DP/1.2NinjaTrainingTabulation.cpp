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
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();                                      // number of days

        vector<vector<int>> dp(n, vector<int>(4, 0));              // dp[day][last] = max points till day if last task was 'last'

        dp[0][0] = max(matrix[0][1], matrix[0][2]);                // if last task was 0, choose task 1 or 2
        dp[0][1] = max(matrix[0][0], matrix[0][2]);                // if last task was 1, choose task 0 or 2
        dp[0][2] = max(matrix[0][0], matrix[0][1]);                // if last task was 2, choose task 0 or 1
        dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});// if no restriction, choose max of all 3

        for(int day = 1; day < n; day++) {                          // loop over days
            for(int last = 0; last < 4; last++) {                  // loop over last task
                dp[day][last] = 0;                                 // initialize dp value
                int maxi = 0;                                      // variable to store maximum points

                for(int task = 0; task < 3; task++) {              // try all 3 tasks
                    if(task != last) {                             // cannot repeat yesterday's task
                        int points = matrix[day][task] + dp[day-1][task]; // current task points + previous best
                        maxi = max(maxi, points);                  // update maximum
                    }
                }
                dp[day][last] = maxi;                              // store best result
            }
        }

        return dp[n-1][3];                                         // return result for last day with no restriction
    }
};

int main() {
    int n;                                                         // variable for number of days
    cin >> n;                                                     // input number of days

    vector<vector<int>> matrix(n, vector<int>(3));                // matrix to store points for each task
    for(int i = 0; i < n; i++) {                                  // loop over days
        for(int j = 0; j < 3; j++) {                              // loop over tasks
            cin >> matrix[i][j];                                  // input task points
        }
    }

    Solution obj;                                                 // create Solution object
    cout << obj.ninjaTraining(matrix);                            // print maximum points

    return 0;                                                     // end of program
}


/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int> &dp, int ind) {
        if (ind == 0) return 1;
        if (ind == 1) return 1;

        if (dp[ind] != -1) return dp[ind];

        int left = helper(dp, ind - 1);
        int right = helper(dp, ind - 2);

        dp[ind] = left + right;
        return dp[ind];
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(dp, n);
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.climbStairs(n);

    return 0;
}

/**/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int helper(vector<int>& height, vector<int>& dp, int ind, int k) {
        if (ind == 0) return 0;

        if (dp[ind] != -1) return dp[ind];

        int ans = INT_MAX;

        for (int j = 1; j <= k; j++) {
            if (ind - j >= 0) {
                int jump = helper(height, dp, ind - j, k)
                           + abs(height[ind] - height[ind - j]);
                ans = min(ans, jump);
            }
        }

        return dp[ind] = ans;
    }

public:
    int minCost(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, -1);
        return helper(height, dp, n - 1, k);
    }
};

int main() {
    int n;
    cin >> n;   // number of stones

    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int k;
    cin >> k;   // max jump allowed

    Solution obj;
    cout << obj.minCost(height, k);

    return 0;
}

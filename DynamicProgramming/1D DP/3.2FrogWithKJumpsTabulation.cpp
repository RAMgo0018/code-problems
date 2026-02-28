/**/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& height, int k) {
        int n = height.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;  // base case

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i],
                                dp[i - j] + abs(height[i] - height[i - j]));
                }
            }
        }

        return dp[n - 1];
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

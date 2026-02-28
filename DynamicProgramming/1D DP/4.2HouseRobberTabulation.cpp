/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];   // kept as you wrote

        for(int i = 1; i < n; i++) {
            int take;   // declare outside if-else

            if(i > 1)
                take = nums[i] + dp[i-2];
            else
                take = nums[i] + 0;

            int notake = 0 + dp[i-1];

            dp[i] = max(take, notake);
        }

        return dp[n-1];
    }
};

int main() {
    int n;
    cin >> n;   // number of houses

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.rob(nums);

    return 0;
}

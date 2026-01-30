/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        /*int n = arr.size();
        int profit = 0;
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                profit = max(profit, arr[i] - arr[j]);
            }
        }
        return profit;*/
        int minval=nums[0];
        int res=0;
        int n=nums.size();
        for(int j=1;j<n;j++)
        {
            if(nums[j]>minval)
            res=max(res,nums[j]-minval);//maintaining a minvlue and current number - minvalue can be the maximum difference or optimum buy sell situtaion so updating max everytime for every minvalue;
            minval=min(minval,nums[j]);
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}

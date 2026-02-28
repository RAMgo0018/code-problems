/*Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

Example:

Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();

        int prev = 0;    // dp[0]
        int prev2 = 0;   // dp[-1] (not used initially)

        for (int i = 1; i < n; i++) {
            int left = prev + abs(height[i] - height[i - 1]);

            int right = INT_MAX;
            if (i > 1) {
                right = prev2 + abs(height[i] - height[i - 2]);
            }

            int curr = min(left, right);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main() {
    int n;
    cin >> n;   // number of stones

    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    cout << obj.minCost(height);

    return 0;
}

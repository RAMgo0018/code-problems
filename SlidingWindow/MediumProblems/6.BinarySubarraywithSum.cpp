/*Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int> &nums, int goal)
    {
        if (goal < 0) return 0;
        int sum = 0;
        int count = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();

        while (r < n)
        {
            sum = sum + nums[r];
            while (sum > goal)
            {
                sum = sum - nums[l];
                l++;
            }
            count = count + r - l + 1;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = func(nums, goal) - func(nums, goal - 1);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int goal;
    cin >> goal;

    Solution obj;
    cout << obj.numSubarraysWithSum(nums, goal);

    return 0;
}

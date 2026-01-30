/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].*/
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
            sum = sum + (nums[r] % 2);
            while (sum > goal)
            {
                sum = sum - (nums[l] % 2);
                l++;
            }
            count = count + r - l + 1;
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = func(nums, k) - func(nums, k - 1);
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

    int k;
    cin >> k;

    Solution obj;
    cout << obj.numberOfSubarrays(nums, k);

    return 0;
}

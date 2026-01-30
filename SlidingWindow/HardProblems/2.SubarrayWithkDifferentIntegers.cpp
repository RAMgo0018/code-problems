/*Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int func(vector<int>& nums, int k)
    {
        int l = 0;
        int r = 0;
        int count = 0;
        unordered_map<int,int> freq;

        while (r < nums.size())
        {
            freq[nums[r]]++;

            while (freq.size() > k)
            {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }

            count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res = func(nums, k) - func(nums, k - 1);
        return res;
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
    cout << obj.subarraysWithKDistinct(nums, k);

    return 0;
}


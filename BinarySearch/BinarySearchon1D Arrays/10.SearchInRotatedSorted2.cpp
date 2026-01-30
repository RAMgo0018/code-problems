/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) 
                return true;

            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // Check if left half is sorted
            if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;  // target in left
                else
                    low = mid + 1;   // target in right
            } 
            else { // Right half is sorted
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;   // target in right
                else
                    high = mid - 1;  // target in left
            }
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    Solution obj;
    cout << (obj.search(nums, target) ? "true" : "false") << endl;

    return 0;
}

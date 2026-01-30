/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) 
                return mid;

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

        return -1;
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
    cout << obj.search(nums, target) << endl;

    return 0;
}

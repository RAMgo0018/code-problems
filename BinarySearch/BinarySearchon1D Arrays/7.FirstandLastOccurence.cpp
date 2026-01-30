/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // move left to find first occurrence
            } 
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return first;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // move right to find last occurrence
            } 
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOccurrence(nums, target);
        if (first == -1)
            return {-1, -1};

        int last = lastOccurrence(nums, target);
        return {first, last};
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
    vector<int> result = obj.searchRange(nums, target);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}

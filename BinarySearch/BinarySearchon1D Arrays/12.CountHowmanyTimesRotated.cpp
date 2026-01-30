/*Given an increasing sorted rotated array arr[] of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr[] = [2, 4, 6, 9], if we rotate it by 2 times it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]

Examples:

Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[mid] >= nums[low]) {
                if (ans > nums[low]) {
                    ans = nums[low];
                    index = low;
                }
                low = mid + 1;
            } 
            // Right half is sorted
            else {
                if (ans > nums[mid]) {
                    ans = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }

        return index;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.findKRotation(nums) << endl;

    return 0;
}

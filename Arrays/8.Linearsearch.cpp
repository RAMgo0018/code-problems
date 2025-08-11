/*Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. If the target is not found in the array, return -1


Examples:
Input: nums = [2, 3, 4, 5, 3], target = 3

Output: 1

Explanation: The first occurence of 3 in nums is at index 1*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        bool flag = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                flag = true;
                return i;
            } else
                continue;
        }
        if (flag == false)
            return -1;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 40, 50};
    int target = 30;

    int index = obj.linearSearch(nums, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}

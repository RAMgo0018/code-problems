/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> mpp;
        
        // Count the frequency of each number
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        
        // Find the number with frequency 1
        for (auto it : mpp) {
            if (it.second == 1)
                return it.first;
        }

        return -1; // default return if not found
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // example input
    Solution obj;
    int ans = obj.singleNumber(nums);
    cout << "Single Number: " << ans << endl;
    return 0;
}

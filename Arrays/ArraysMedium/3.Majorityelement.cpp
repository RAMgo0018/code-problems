/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int,int> mpp;
        for (int i = 0; i < nums.size(); i++) 
        {
            mpp[nums[i]]++; //creating map and storing frequencies of every element 
        }
        for (auto it : mpp) 
        {
            if (it.second > nums.size() / 2) //checking if frequency is greater than n/2
            {
                return it.first;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = sol.majorityElement(nums);

    if (ans == -1) 
        cout << "No majority element found." << endl;
    else 
        cout << "Majority element: " << ans << endl;

    return 0;
}

/*Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {// Function to find the maximum number of consecutive 1's in the binary array
        int count=0;
        int res=0;;
        for(int i=0;i<nums.size();i++)
        {
             res=max(res,count);
            if(nums[i]==1)
            count++;
            else{
            //if(arr[i]!=1)
            count=0;
            continue;
            }
        }
        res=max(res,count);
        return res;
        
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1}; // sample input
    Solution sol;
    int ans = sol.findMaxConsecutiveOnes(nums);
    cout << "Max consecutive ones: " << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int maxSubArray(vector<int>& nums) {
        int res=nums[0]; // Earlier I was doing res=0 and res=-1
        int currsum=nums[0];

        for(int i=1;i<nums.size();i++) {
            currsum=max(currsum+nums[i],nums[i]);
            res=max(res,currsum);
        }
        return res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int max_normal=maxSubArray(nums);
        int sum=0;
        if(max_normal<0) // I was missing this thing earlier
            return max_normal;
        for(int i=0;i<nums.size();i++) {
            sum=sum+nums[i];
            nums[i]=-nums[i];
        }
        int inverted_max=maxSubArray(nums);
        int total_sum=inverted_max+sum;
        return max(max_normal,total_sum);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {5, -3, 5};
    cout << "Circular Max Subarray Sum: " << sol.maxSubarraySumCircular(nums1) << endl;

    // Example 2
    vector<int> nums2 = {-3, -2, -5};
    cout << "Circular Max Subarray Sum: " << sol.maxSubarraySumCircular(nums2) << endl;

    // Example 3
    vector<int> nums3 = {1, -2, 3, -2};
    cout << "Circular Max Subarray Sum: " << sol.maxSubarraySumCircular(nums3) << endl;

    return 0;
}

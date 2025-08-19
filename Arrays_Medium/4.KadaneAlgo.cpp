#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int res=nums[0];//Earlier I was doing res=0 and res=-1
        int currsum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            currsum=max(currsum+nums[i],nums[i]);
            res=max(res,currsum);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int result = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

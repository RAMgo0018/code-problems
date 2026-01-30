/*Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.

 

Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMax(vector<int>& nums) {
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    int getSum(vector<int>& nums, int divisor) {
        int tsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            tsum += ceil((double)nums[i] / divisor);
        }
        return tsum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = getMax(nums);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int tsum = getSum(nums, mid);

            if (tsum <= threshold) {
                ans = mid; 
                high = mid - 1; // try smaller divisor
            } else {
                low = mid + 1;  // need bigger divisor
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int threshold;
    cin >> threshold;

    Solution obj;
    cout << obj.smallestDivisor(nums, threshold) << endl;

    return 0;
}

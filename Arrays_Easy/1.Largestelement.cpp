//Given an array of integers nums, return the value of the largest element in the array
/*Examples:
Input: nums = [3, 3, 6, 1]

Output: 6

Explanation: The largest element in array is 6*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> // Optional, for STL version

using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums){// Function to find the largest element in the array{
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest)
                largest = nums[i];
        }
        return largest;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {5, 1, 8, 3, 2, 10, 7};

    int largest = obj.largestElement(nums);

    cout << "The largest element is: " << largest << endl;

    return 0;
}

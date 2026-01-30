/*Given an array arr, use selection sort to sort arr[] in increasing order.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: Maintain sorted (in bold) and unsorted subarrays. Select 1. Array becomes 1 4 3 9 7. Select 3. Array becomes 1 3 4 9 7. Select 4. Array becomes 1 3 4 9 7. Select 7. Array becomes 1 3 4 7 9. Select 9. Array becomes 1 3 4 7 9*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            int minindex = i;
            for(int j = i; j < n; j++)
            {
                if(nums[j] < nums[minindex])
                    minindex = j;
            }
            int temp;
            temp = nums[i];
            nums[i] = nums[minindex];
            nums[minindex] = temp;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    obj.selectionSort(nums);

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}

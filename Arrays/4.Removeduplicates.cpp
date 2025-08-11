/* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if (arr.empty()) return 0; // edge case: empty array

        int count = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[count - 1]) {
                arr[count] = arr[i];
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};

    int newLength = obj.removeDuplicates(arr);

    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

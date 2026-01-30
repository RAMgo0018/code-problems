/* Given an array arr[], check whether it is sorted in non-decreasing order. Return true if it is sorted otherwise false.

Examples:

Input: arr[] = [10, 20, 30, 40, 50]
Output: true
Explanation: The given array is sorted.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSorted(vector<int>& arr) {// Function to check if the array is sorted in non-decreasing order
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 2, 2, 4, 5};

    if (obj.isSorted(arr))
        cout << "The array is sorted." << endl;
    else
        cout << "The array is NOT sorted." << endl;

    return 0;
}

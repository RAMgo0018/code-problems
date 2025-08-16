/*You are given an array arr[] of non-negative integers. You have to move all the zeros in the array to the right end while maintaining the relative order of the non-zero elements. The operation must be performed in place, meaning you should not use extra space for another array.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[count];
                arr[count] = temp;
                count++;
            }
        }
    }
};

int main() {
    Solution obj;
    vector<int> arr = {0, 1, 0, 3, 12};

    obj.pushZerosToEnd(arr);

    cout << "Array after pushing zeros to end: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

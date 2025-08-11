/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). This array represents a permutation of the integers from 1 to n with one element missing. Your task is to identify and return the missing element.

Examples:

Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNum(vector<int>& arr) {// Function to find the missing number in the array
        long n = arr.size() + 1;  // total numbers including the missing one
        long long max = (n * (n + 1)) / 2; // sum of first n natural numbers
        long long sum = 0;

        for (int i = 0; i < n - 1; i++) {
            sum = sum + arr[i];
        }

        return max - sum; // missing number
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 4, 5}; // missing number should be 3

    int missing = obj.missingNum(arr);

    cout << "The missing number is: " << missing << endl;

    return 0;
}

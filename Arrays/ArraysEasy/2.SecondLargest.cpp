/*Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.
Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int getSecondLargest(const vector<int> &arr){ // Function to find the second largest element in the array
        if (arr.size() < 2) return -1;
        int largest = INT_MIN, secondLargest = INT_MIN;

        for (int num : arr) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input. Expected a positive integer.\n";
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.getSecondLargest(arr);

    if (result == -1) {
        cout << "No second largest distinct element found.\n";
    } else {
        cout << "The second largest distinct element is: " << result << "\n";
    }

    return 0;
}

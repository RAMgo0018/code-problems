/*Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findUnion(const vector<int> &a, const vector<int> &b) {// Function to find the union of two sorted arrays
        int i = 0, j = 0;
        vector<int> result;

        while (i < a.size() && j < b.size()) {// Traverse both arrays
            // If current elements are different, add the smaller one to the result
            // and move the pointer of that array forward
            if (a[i] < b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
            } else if (b[j] < a[i]) {// If current elements are different, add the smaller one to the result
                // and move the pointer of that array forward
                if (result.empty() || result.back() != b[j]) {
                    result.push_back(b[j]);
                }
                j++;
            } else { // a[i] == b[j]
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            }
        }

        while (i < a.size()) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }
            i++;
        }

        while (j < b.size()) {
            if (result.empty() || result.back() != b[j]) {
                result.push_back(b[j]);
            }
            j++;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 3, 5, 7};

    vector<int> result = obj.findUnion(arr1, arr2);

    cout << "Union of arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

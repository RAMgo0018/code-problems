/*Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void reverseArr(vector<int>& arr, int start, int end) 
    {
        while (start < end) 
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void rotateArr(vector<int>& arr, int d) // Function to rotate the array to the left by d steps
    {
        int n = arr.size();
        if (n == 0) return; // edge case
        d = d % n; // Handle d > n

        // Step 1: Reverse first d elements
        reverseArr(arr, 0, d - 1);

        // Step 2: Reverse the rest
        reverseArr(arr, d, n - 1);

        // Step 3: Reverse the whole array
        reverseArr(arr, 0, n - 1);
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    obj.rotateArr(arr, d);

    cout << "Array after rotation: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to swap two integers
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Function to reverse a 1D array (used for each row)
    void reverseArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        // Two pointer approach to reverse the array
        while(left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    // Function to rotate the matrix 90 degrees clockwise
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();   // number of rows (and columns)

        // STEP 1: Transpose the matrix
        // Convert rows into columns
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // STEP 2: Reverse each row
        // This gives 90° clockwise rotation
        for(int i = 0; i < n; i++) {
            reverseArray(matrix[i]);
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    obj.rotate(matrix);   // Rotate matrix

    // Output rotated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

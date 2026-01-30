/*You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:

The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.
Examples:

Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.*/
#include <bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int maxcount = 0;
        int cnt_1 = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            cnt_1 = m - lowerBound(arr[i], 1);
            if (cnt_1 > maxcount) {
                maxcount = cnt_1;
                index = i;
            }
        }
        return index;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    Solution obj;
    cout << obj.rowWithMax1s(arr) << endl;

    return 0;
}

/*Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

Examples:

Input: mat[][] = [[1, 3, 5], 
                [2, 6, 9], 
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int ans = arr.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;   // index of first element > target
    }

    int countSmallerEqual(vector<vector<int>>& mat, int mid, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(mat[i], mid);
        }
        return cnt;
    }

    int median(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 1, high = 1e9;   // safe bounds
        int req = (n * m) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int elements = countSmallerEqual(mat, mid, n);

            if (elements <= req)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    cout << obj.median(mat);

    return 0;
}

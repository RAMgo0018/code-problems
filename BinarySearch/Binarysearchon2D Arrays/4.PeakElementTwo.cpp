/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findmax(vector<vector<int>>& mat, int row, int col, int mid) {
        int maxi = INT_MIN;
        int index = -1;
        for(int i = 0; i < row; i++) {
            if(mat[i][mid] > maxi) {
                maxi = mat[i][mid];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = findmax(mat, n, m, mid);

            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if(mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};
            else if(mat[row][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution obj;
    vector<int> ans = obj.findPeakGrid(mat);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}

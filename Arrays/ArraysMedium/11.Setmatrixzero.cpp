/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();        // number of rows
        int m = matrix[0].size();     // number of columns
        int col0 = 1;                 // flag to track if first column should be zero

        // First pass: mark rows and columns to be zeroed
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;      // mark the first cell of the row
                    if(j != 0)
                        matrix[0][j] = 0;  // mark the first cell of the column
                    else
                        col0 = 0;          // first column itself needs to be zeroed
                }
            }
        }

        // Second pass: update the matrix using marks, skip first row and first column for now
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != 0) {
                    // if either the first row or first column of this cell is zero, set it to zero
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row separately
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }

        // Handle the first column separately
        if(col0 == 0) {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};  



int main() {
    int n, m;
    cin >> n >> m;  // input rows and columns

    vector<vector<int>> matrix(n, vector<int>(m));

    // input matrix elements
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];

    Solution obj;
    obj.setZeroes(matrix);  // modify matrix in-place

    // output the updated matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
/*BETTER APPROACH
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                row[i]=1;
                col[j]=1;
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(row[i]==1||col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};*/



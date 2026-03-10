/*You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.

 

Example 1:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

 void dfs(vector<vector<int>>& image, vector<vector<int>> &ans, int row, int col, int newcolor, int inicolor, vector<int> drow, vector<int> dcol) // DFS function
 {
    int n = image.size(); // number of rows
    int m = image[0].size(); // number of columns

    ans[row][col] = newcolor; // color the current pixel

    for(int i = 0; i < 4; i++) // explore 4 directions
    {
        int nrow = drow[i] + row; // new row
        int ncol = dcol[i] + col; // new column

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != newcolor) // check boundaries and same color
        {
            dfs(image, ans, nrow, ncol, newcolor, inicolor, drow, dcol); // recursive DFS call
        }
    }
 }

 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) // main flood fill logic
 {
        int inicolor = image[sr][sc]; // store initial color

        vector<vector<int>> ans = image; // copy image to answer matrix

        vector<int> drow = {-1,0,1,0}; // row movement (up,right,down,left)
        vector<int> dcol = {0,1,0,-1}; // column movement

        dfs(image, ans, sr, sc, color, inicolor, drow, dcol); // start DFS

        return ans; // return filled image
 }
};

int main()
{
    int n,m; // rows and columns
    cout<<"Enter rows and columns: ";
    cin>>n>>m;

    vector<vector<int>> image(n, vector<int>(m)); // create image matrix

    cout<<"Enter image values:\n";
    for(int i=0;i<n;i++) // input matrix
    {
        for(int j=0;j<m;j++)
        {
            cin>>image[i][j];
        }
    }

    int sr,sc,color; // starting row, column, new color
    cout<<"Enter starting row, column and new color: ";
    cin>>sr>>sc>>color;

    Solution obj; // object of solution class

    vector<vector<int>> result = obj.floodFill(image, sr, sc, color); // call function

    cout<<"Flood Filled Image:\n";
    for(int i=0;i<n;i++) // print result matrix
    {
        for(int j=0;j<m;j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0; // end program
}
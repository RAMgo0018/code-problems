/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int row, int col) {

        int n = board.size(); // number of rows
        int m = board[0].size(); // number of columns

        visited[row][col] = 1; // mark current cell as visited

        vector<int> delrow = {-1, 0, 1, 0}; // row movement directions (up, right, down, left)
        vector<int> delcol = {0, 1, 0, -1}; // column movement directions

        for(int i = 0; i < 4; i++) { // check all 4 directions

            int newrow = row + delrow[i]; // compute new row
            int newcol = col + delcol[i]; // compute new column

            if(newrow >= 0 && newrow < n &&   // check row boundary
               newcol >= 0 && newcol < m &&   // check column boundary
               board[newrow][newcol] == 'O' && // check if cell is O
               !visited[newrow][newcol]) {     // check if not visited

                dfs(board, visited, newrow, newcol); // recursive DFS
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size(); // number of rows
        int m = board[0].size(); // number of columns

        vector<vector<int>> visited(n, vector<int>(m, 0)); // visited matrix

        for(int j = 0; j < m; j++) { // traverse first and last row

            if(!visited[0][j] && board[0][j] == 'O') // check first row
                dfs(board, visited, 0, j); // DFS from first row

            if(!visited[n-1][j] && board[n-1][j] == 'O') // check last row
                dfs(board, visited, n-1, j); // DFS from last row
        }

        for(int i = 0; i < n; i++) { // traverse first and last column

            if(!visited[i][0] && board[i][0] == 'O') // check first column
                dfs(board, visited, i, 0); // DFS from first column

            if(!visited[i][m-1] && board[i][m-1] == 'O') // check last column
                dfs(board, visited, i, m-1); // DFS from last column
        }

        for(int i = 0; i < n; i++) { // traverse whole board
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O' && !visited[i][j]) // surrounded region
                    board[i][j] = 'X'; // convert O to X
            }
        }
    }
};

int main() {

    int n, m;
    cout << "Enter number of rows: ";
    cin >> n; // input rows

    cout << "Enter number of columns: ";
    cin >> m; // input columns

    vector<vector<char>> board(n, vector<char>(m)); // create board

    cout << "Enter board values (X or O):\n";
    for(int i = 0; i < n; i++) { // input board
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj; // create solution object
    obj.solve(board); // call solve function

    cout << "\nUpdated Board:\n";
    for(int i = 0; i < n; i++) { // print board
        for(int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0; // end program
}
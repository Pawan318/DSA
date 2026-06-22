class Solution {
public:
    // Stores all possible valid board configurations
    vector<vector<string>> ans;

    // Function to check whether placing a queen at (row, col) is safe
    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check the same column in previous rows
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check the upper-left diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Check the upper-right diagonal
        i = row;
        j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j++;
        }

        // Current position is safe for placing a queen
        return true;
    }

    // Backtracking function to place queens row by row
    void solve(int row, vector<string>& board, int n) {

        // Base case: all queens are placed successfully
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {

            // Check whether the current position is safe
            if (isSafe(row, col, board, n)) {

                // Place the queen at (row, col)
                board[row][col] = 'Q';

                // Recursively place queens in the next row
                solve(row + 1, board, n);

                // Backtrack: remove the queen and try another column
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        // Initialize an empty n x n board with '.'
        vector<string> board(n, string(n, '.'));

        // Start placing queens from the first row
        solve(0, board, n);

        // Return all valid board configurations
        return ans;
    }
};
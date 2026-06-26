class Solution {
public:

    // Checks whether the given digit can be placed at (row, col)
    // without violating any Sudoku rules.
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Check if the digit already exists in the current row.
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig)
                return false;
        }

        // Check if the digit already exists in the current column.
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig)
                return false;
        }

        // Find the starting cell of the corresponding 3x3 subgrid.
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        // Check whether the digit already exists in the 3x3 subgrid.
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig)
                    return false;
            }
        }

        // The digit can be placed safely.
        return true;
    }

    // Backtracking function that fills the Sudoku board.
    bool solve(vector<vector<char>>& board, int row, int col) {

        // Base Case:
        // If we have processed all rows, the Sudoku is solved.
        if (row == 9)
            return true;

        // Compute the coordinates of the next cell.
        int nextRow = row;
        int nextCol = col + 1;

        // Move to the first column of the next row after reaching
        // the end of the current row.
        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // Skip cells that are already filled.
        if (board[row][col] != '.') {
            return solve(board, nextRow, nextCol);
        }

        // Try every possible digit from '1' to '9'.
        for (char dig = '1'; dig <= '9'; dig++) {

            // Place the digit only if it satisfies Sudoku constraints.
            if (isSafe(board, row, col, dig)) {

                // Choose
                board[row][col] = dig;

                // Explore
                if (solve(board, nextRow, nextCol))
                    return true;

                // Unchoose (Backtrack)
                // Undo the current choice and try another digit.
                board[row][col] = '.';
            }
        }

        // No valid digit can be placed in this cell.
        return false;
    }

    // Driver function that starts solving the Sudoku.
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
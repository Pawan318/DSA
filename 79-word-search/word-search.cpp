class Solution {
public:

    // DFS function to check whether the word can be formed
    // starting from the current cell (row, col)
    bool dfs(vector<vector<char>>& board, string word, int index, int row, int col) {

        // Base case: if all characters of the word are matched
        if (index == word.size())
            return true;

        // Boundary conditions:
        // 1. row or col goes out of the board
        // 2. current character does not match the required character
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size() ||
            board[row][col] != word[index]) {
            return false;
        }

        // Store the current character and mark the cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all four directions (down, up, right, left)
        bool found =
            dfs(board, word, index + 1, row + 1, col) || // Down
            dfs(board, word, index + 1, row - 1, col) || // Up
            dfs(board, word, index + 1, row, col + 1) || // Right
            dfs(board, word, index + 1, row, col - 1);   // Left

        // Backtrack: restore the original character
        board[row][col] = temp;

        // Return whether the word was found in any direction
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        // Traverse each cell of the board
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                // Start DFS only if the first character matches
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true; // Word found
                }
            }
        }

        // Word does not exist in the board
        return false;
    }
};
class Solution {
public:
  bool dfs(vector<vector<char>>& board, string word,int index, int row, int col){
       if(index == word.size()) return true;
       // Check the boundig codition
       if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]){
        return false;
       }
        // Mark the row and coloum as a visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Recursion for all the directions
        bool found = dfs(board, word, index+1, row+1, col) || 
                     dfs(board, word, index+1, row-1, col) ||
                     dfs(board, word, index+1, row, col+1) || 
                     dfs(board, word, index+1, row, col-1);

        board[row][col] = temp;

    return found;
 }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
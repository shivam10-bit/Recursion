class Solution {
public:
    bool dfs(vector<vector<char>>& board,
             string& word,
             int i,
             int j,
             int idx) {

        if (board[i][j] != word[idx])
            return false;

        if (idx == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dir[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < rows &&
                nj >= 0 && nj < cols &&
                board[ni][nj] != '#') {

                if (dfs(board, word, ni, nj, idx + 1)) {
                    return true;
                }
            }
        }

        board[i][j] = temp; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};
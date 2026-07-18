class Solution {
public:
    bool dfs(vector<vector<bool>>& vis, int i, int j, int dr[], int dc[],
             string word, vector<vector<char>>& board, int l) {
        int r = board.size();
        int c = board[0].size();

        if (l == word.size() - 1)
            return true;

        vis[i][j] = true;

        for (int a = 0; a < 4; a++) {

            int x = i + dr[a];
            int y = j + dc[a];
            if (x >= 0 && x < r && y >= 0 && y < c && !vis[x][y] &&
                board[x][y] == word[l + 1]) {
                if (dfs(vis, x, y, dr, dc, word, board, l + 1))
                    return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(visited, i, j, dr, dc, word, board, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans,vector<string> &board,int n,int i){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,i,j,n)){
                board[i][j]='Q';
                solve(ans,board,n,i+1);
                board[i][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(ans,board,n,0);
        return ans;
    }
};
class Solution {
public:
    void convert(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {  
                if (board[i][j] == 'B')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    bool isValid(int i, int j, int n, int m, vector<vector<char>>& board) {
        if (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == 'O') {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m) {
        board[i][j] = 'B';  
        if (isValid(i + 1, j, n, m, board)) {
            dfs(board, i + 1, j, n, m);
        }
        if (isValid(i - 1, j, n, m, board)) {
            dfs(board, i - 1, j, n, m);
        }
        if (isValid(i, j + 1, n, m, board)) {
            dfs(board, i, j + 1, n, m);
        }
        if (isValid(i, j - 1, n, m, board)) {
            dfs(board, i, j - 1, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;  
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, n, m);
            }
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1, n, m);
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j, n, m);
            }
            if (board[n - 1][j] == 'O') {
                dfs(board, n - 1, j, n, m);
            }
        }
        convert(board);
    }
};
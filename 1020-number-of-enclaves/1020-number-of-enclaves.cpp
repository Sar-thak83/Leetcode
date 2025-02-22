class Solution {
public:
    int count(vector<vector<int>>& grid, int n, int m) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count ;
    }

    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1) {
            return true;
        }
        return false;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        grid[i][j] = 2;
        if (isValid(i + 1, j, n, m, grid)) {
            dfs(grid, i + 1, j, n, m);
        }
        if (isValid(i - 1, j, n, m, grid)) {
            dfs(grid, i - 1, j, n, m);
        }
        if (isValid(i, j + 1, n, m, grid)) {
            dfs(grid, i, j + 1, n, m);
        }
        if (isValid(i, j - 1, n, m, grid)) {
            dfs(grid, i, j - 1, n, m);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0, n, m);
            }
            if (grid[i][m - 1] == 1) {
                dfs(grid, i, m - 1, n, m);
            }
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs(grid, 0, j, n, m);
            }
            if (grid[n - 1][j] == 1) {
                dfs(grid, n - 1, j, n, m);
            }
        }
        return count(grid, n, m);
    }
};
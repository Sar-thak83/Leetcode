class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        int total_fresh = 0; 
        int time = 0;       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    total_fresh++; 
                }
                if (grid[i][j] == 2) {
                    q.push({i, j}); 
                }
            }
        }
        if (total_fresh == 0) return 0;
        int a[4] = {0, 0, 1, -1};
        int b[4] = {1, -1, 0, 0};
        while (!q.empty()) {
            int size = q.size();
            bool rotted = false; 
            for (int i = 0; i < size; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + a[d], ny = y + b[d];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        total_fresh--;   
                        q.push({nx, ny});
                        rotted = true;    
                    }
                }
            }
            if (rotted) {
                time++;
            }
        }
        return total_fresh == 0 ? time : -1; 
    }
};
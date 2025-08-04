class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (m == 0 || n == 0)
            return -1;
            
        auto is_Safe = [&](int x, int y) {
            return (x >= 0 && x < m && y >= 0 && y < n);
        };
        
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        int maxHeight = grid[0][0];
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            maxHeight = max(maxHeight, height);
            
            if (x == m - 1 && y == n - 1) {
                return maxHeight;
            }
            
            for (auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                
                if (is_Safe(newX, newY) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    pq.push({grid[newX][newY], {newX, newY}});
                }
            }
        }
        
        return -1;
    }
};
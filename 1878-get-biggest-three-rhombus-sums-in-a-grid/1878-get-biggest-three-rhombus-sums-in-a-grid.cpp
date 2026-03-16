class Solution {
public:

    bool check_bounds(vector<vector<int>>& grid, vector<pair<int,int>> v){
        int m = grid.size();
        int n = grid[0].size();

        for(auto &pt : v){
            if(pt.first < 0 || pt.first >= m || pt.second < 0 || pt.second >= n){
                return false;
            }
        }
        return true;
    }

    bool get_all_v(vector<vector<int>>& grid, vector<pair<int,int>>& v, pair<int,int> c, int delta){

        pair<int,int> A(c.first - delta, c.second);
        pair<int,int> B(c.first, c.second + delta);
        pair<int,int> C(c.first + delta, c.second);
        pair<int,int> D(c.first, c.second - delta);
        v[0] = A;
        v[1] = B;
        v[2] = C;
        v[3] = D;
        if(check_bounds(grid, v)) return true;

        return false;
    }
    void getAllSum(vector<vector<int>>& grid, int cx, int cy, priority_queue<int>& pq){
        pq.push(grid[cx][cy]);

        int delta = 1;
        vector<pair<int,int>> v(4);
        while(get_all_v(grid, v, {cx,cy}, delta)){
            pair<int,int> A = v[0];
            pair<int,int> B = v[1];
            pair<int,int> C = v[2];
            pair<int,int> D = v[3];
            int c_sum = grid[A.first][A.second] +
                        grid[B.first][B.second] +
                        grid[C.first][C.second] +
                        grid[D.first][D.second];
            for(int i = 1; i < (B.first - A.first); i++){
                c_sum += grid[A.first + i][A.second + i];
            }
            for(int i = 1; i < (C.first - B.first); i++){
                c_sum += grid[B.first + i][B.second - i];
            }
            for(int i = 1; i < (C.first - D.first); i++){
                c_sum += grid[C.first - i][C.second - i];
            }
            for(int i = 1; i < (D.first - A.first); i++){
                c_sum += grid[D.first - i][D.second + i];
            }
            pq.push(c_sum);
            delta++;
        }
    }
    bool can_push(vector<int> ans, int top){
        for(auto val : ans){
            if(val == top) return false;
        }
        return true;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;

        int m = grid.size();
        int n = grid[0].size();
        priority_queue<int> pq;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                getAllSum(grid, i, j, pq);
            }
        }
        while(!pq.empty() && ans.size() < 3){

            int top = pq.top();
            pq.pop();
            if(can_push(ans, top)){
                ans.push_back(top);
            }
        }

        return ans;
    }
};
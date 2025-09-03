class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int,int>> arr;
        for (auto &p : points) {
            arr.push_back({p[0], -p[1]});
        }
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int y1 = -arr[i].second;
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int y2 = -arr[j].second;
                if (y2 > maxY && y2 <= y1) {
                    ans++;
                    maxY = y2;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    typedef pair<int, int> p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto vec : times) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        vector<int> distance(n + 1, INT_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, k});
        distance[k] = 0;
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int time = it.second;
                if (distance[v] > dist + time) {
                    distance[v] = dist + time;
                    pq.push({dist + time, v});
                }
            }
        }
        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            minTime = max(minTime, distance[i]);
        }
        return minTime;
    }
};
class Solution {
public:
    typedef pair<int , int> p;
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod =1e9+7;
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> distance(n, INT_MAX);
        vector<int> ways(n, 0);
        priority_queue<p, vector<p>, greater<p>> pq;
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int w = it.second;
                if (dist + w < distance[adjnode]) {
                    distance[adjnode] = dist + w;
                    pq.push({dist + w, adjnode});
                    ways[adjnode] = ways[node];
                } else if (dist + w == distance[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                }
            }
        }
        return ways[n - 1]%mod;
    }
};
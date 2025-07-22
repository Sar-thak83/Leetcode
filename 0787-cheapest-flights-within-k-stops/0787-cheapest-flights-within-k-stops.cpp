class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        unordered_map<int, list<pair<int, int>>> adj;
        for (vector<int>& vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            adj[u].push_back({v, w});
        }
        vector<int> distance(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src,0});
        distance[src] = 0;
        int steps = 0;
        while (!q.empty() && steps <= k) {
            int size = q.size();
            while (size--) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                for (pair<int, int>& p : adj[node]) {
                    int v = p.first;
                    int cost = p.second;
                    if (distance[v] > dist + cost) {
                        distance[v] = dist + cost;
                        q.push({v, dist + cost});
                    }
                }
            }
            steps++;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
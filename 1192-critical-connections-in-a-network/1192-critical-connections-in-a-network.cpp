class Solution {
public:
    void dfs(int& timer, int parent, vector<int>& dis, vector<int>& low,
             vector<vector<int>>& result, int node, vector<vector<int>>& adj,
             vector<bool>& vis) {
        vis[node] = true;
        dis[node] = low[node] = timer++;
        
        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue;
            }
            else if(!vis[nbr]){
                dfs(timer, node, dis, low, result, nbr, adj, vis);
                low[node] = min(low[node], low[nbr]);
                if(low[nbr] > dis[node]){
                    vector<int> ans;
                    ans.push_back(node);
                    ans.push_back(nbr);
                    result.push_back(ans);
                }
            }
            else{
                low[node] = min(low[node], dis[nbr]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> result;
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer = 0;
        vector<int> dis(n, -1);
        vector<int> low(n, -1);
        vector<bool> vis(n, false);
        int parent = -1;
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(timer, parent, dis, low, result, i, adj, vis);
            }
        }
        return result;
    }
};
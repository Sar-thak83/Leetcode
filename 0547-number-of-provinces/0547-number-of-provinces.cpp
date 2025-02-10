class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&visited) {

        visited[node]=1;
        for (auto neighbour : adj[node]){
            if(!visited[neighbour])
            dfs(neighbour,adj,visited);
        }
        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0 ;
        int n = isConnected.size();
         vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(isConnected[i][j]==1 && i!=j)
                adj[i].push_back(j);
            }
        }
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};


// #include <vector>
// using namespace std;

// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
//         visited[node] = 1; // Mark the current node as visited
//         for (auto neighbour : adj[node]) {
//             if (!visited[neighbour]) { // Only visit unvisited neighbours
//                 dfs(neighbour, adj, visited);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size(); // Number of nodes
//         vector<vector<int>> adj(n); // Adjacency list

//         // Build the adjacency list
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (isConnected[i][j] == 1 && i != j) { // Avoid self-loops
//                     adj[i].push_back(j); // Add edge from i to j
//                 }
//             }
//         }

//         vector<int> visited(n, 0); // Visited array
//         int count = 0; // Count of connected components

//         // Perform DFS for each unvisited node
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 count++; // Increment count for each new connected component
//                 dfs(i, adj, visited); // Perform DFS to mark all nodes in the component
//             }
//         }

//         return count; // Return the number of connected components
//     }
// };
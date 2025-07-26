class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};
    class Solution {
    public:
        int removeStones(vector<vector<int>>& stones) {
            int n=stones.size();
            int maxRow = 0;
            int maxCol = 0;
            for (auto it : stones) {
                maxRow = max(maxRow, it[0]);
                maxCol = max(maxCol, it[1]);
            }
            DisjointSet ds(maxRow + maxCol + 1);
            unordered_map<int, int> stoneNodes;
            for (auto it : stones) {
                int nodeRow = it[0];
                int nodeCol = it[1] + maxRow + 1;
                ds.unionSets(nodeRow, nodeCol);
                stoneNodes[nodeRow] = 1;
                stoneNodes[nodeCol] = 1;
            }

            int cnt = 0;
            for (auto it : stoneNodes) {
                if (ds.find(it.first) == it.first) {
                    cnt++;
                }
            }
            return n - cnt;
        }
    };
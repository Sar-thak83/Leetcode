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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionSets(i, mapMailNode[mail]);
                }
            }

        }

        vector<vector<string>> mergeMail(n);
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.find(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i=0;i<n;i++ ){
            if(mergeMail[i].size()==0){
                continue;
            }
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for (auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
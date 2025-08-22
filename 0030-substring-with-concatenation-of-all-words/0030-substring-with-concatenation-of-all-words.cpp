class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        
        unordered_map<string, int> count;
        vector<int> ans;
        int n = words.size();
        int k = words[0].size();

        for (auto& word : words) {
            ++count[word];
        }

        for (int i = 0; i <= (int)s.size() - k * n; ++i) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < n; ++j) {
                string w = s.substr(i + j * k, k);
                if (++seen[w] > count[w]) break;
            }
            if (j == n) ans.push_back(i);
        }

        return ans;
    }
};

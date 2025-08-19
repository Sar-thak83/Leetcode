// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int n = strs.size();
//         vector<string> temp(n);
//         vector<vector<string>> ans;
//         vector<bool> used(n, false);
        
//         for (int i = 0; i < n; i++) {
//             string s = strs[i];
//             sort(s.begin(), s.end());
//             temp[i] = s;
//         }

//         for (int i = 0; i < n; i++) {
//             if (used[i])
//                 continue;
//             vector<string> group;
//             group.push_back(strs[i]);
//             used[i] = true;
//             for (int j = i + 1; j < n; j++) {
//                 if (!used[j] && temp[i] == temp[j]) {
//                     group.push_back(strs[j]);
//                     used[j] = true;
//                 }
//             }
//             ans.push_back(group);
//         }
//         return ans;
//     }
// };



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            groups[sorted_s].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto& kv : groups) {
            ans.push_back(move(kv.second));
        }
        
        return ans;
    }
}; 
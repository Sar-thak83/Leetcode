// class Solution {
// public:
//     typedef pair<int, pair<int, int>> p;
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
//                                        int k) {
//         priority_queue<p, vector<p>> pq;
//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = 0; j < nums2.size(); j++) {
//                 int sum = nums1[i] + nums2[j];
//                 if (pq.size() < k) {
//                     pq.push({sum, {i, j}});
//                 } else if (pq.top().first > sum) {
//                     pq.pop();
//                     pq.push({sum, {i, j}});
//                 } else
//                     break;
//             }
//         }
//         vector<vector<int>> ans;
//         while (!pq.empty()) {
//             auto temp = pq.top();
//             pq.pop();
//             int i = temp.second.first;
//             int j = temp.second.second;
//             ans.push_back({nums1[i], nums2[j]});
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = nums1.size();
        int m = nums2.size();
        
        if (n == 0 || m == 0) return ans;
        
        pq.push({nums1[0] + nums2[0], {0, 0}});
        
        while (!pq.empty() && ans.size() < k) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
            if (j == 0 && i + 1 < n) {
                pq.push({nums1[i + 1] + nums2[0], {i + 1, 0}});
            }
        }
        
        return ans;
    }
};
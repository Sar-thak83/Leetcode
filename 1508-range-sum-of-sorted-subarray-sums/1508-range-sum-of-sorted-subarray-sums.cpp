// ----------------------Brutre force------------------------

// class Solution {
// public:
//     int m = 1e9 + 7;
//     void subArraySum(vector<int>& temp, vector<int> nums, int n) {
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 temp.push_back(sum % m);
//             }
//         }
//     }
//     int rangeSum(vector<int>& nums, int n, int left, int right) {
//         vector<int> ans;
//         subArraySum(ans, nums, n);
//         sort(ans.begin(), ans.end());
//         int sum = 0;
//         for (int i = left - 1; i < right; i++)
//             sum = (sum + ans[i]) % m;
//         return sum % m;
//     }
// };

//-----------------Heap-------------------

class Solution {
public:
    typedef pair<int, int> p;
    int m = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums[i], i});
        int ans = 0;
        for (int count = 1; count <= right; count++) {
            auto p = pq.top();
            pq.pop();
            int sum = p.first;
            int index = p.second;
            if (count >= left)
                ans = (ans + sum )% m;
            int new_index = index + 1;
            if (new_index < n) {
                pq.push({sum + nums[new_index],new_index}) ;
            }
        }
        return ans;
    }
};

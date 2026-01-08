class Solution {
public:
    int n;
    int m;
    int t[501][501];

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if (i == n || j == m)
            return -100000000;
        if (t[i][j] != -1e9)
            return t[i][j];

        int val = nums1[i] * nums2[j];

        int take_i_j = solve(nums1, nums2, i + 1, j + 1) + val;

        int take_i = solve(nums1, nums2, i, j + 1);
        int take_j = solve(nums1, nums2, i + 1, j);

        return t[i][j] = max({val, take_i_j, take_i, take_j});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        for(int i = 0; i<501; i++) {
            for(int j = 0; j < 501; j++) {
                t[i][j] = -1e9;
            }
        }

        return solve(nums1, nums2, 0, 0);
    }
};
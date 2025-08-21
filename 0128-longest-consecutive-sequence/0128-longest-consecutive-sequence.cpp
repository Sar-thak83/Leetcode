class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count = 0, save = 0, Diff;
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) {
            return 0;
        } else {
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] != nums[i]) {
                    Diff = (nums[i] - nums[i-1]);
                    if (Diff == 1) {
                        count++;
                        if (count > save) {
                            save = count;
                        }
                    } else {
                        count = 0;
                    }
                }
            }
            return save + 1;
        }
    }
};
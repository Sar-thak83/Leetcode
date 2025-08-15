class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach = 0, lastjumpIdx = 0, totaljump = 0;
        int destination = nums.size() - 1;
        for (int i = 0; i < destination; i++) {
            maxreach = max(maxreach, i + nums[i]);
            if (i == lastjumpIdx) {
                lastjumpIdx = maxreach;
                totaljump++;
            }
            if (lastjumpIdx >= destination) {
                break;
            }
        }
        return totaljump;
    }
};

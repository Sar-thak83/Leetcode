class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums, 0, 0, target);
    }
    
    int backtrack(vector<int>& nums, int index, int currentSum, int target) {
        if (index == nums.size()) {
            return currentSum == target ? 1 : 0;
        }
        
        int add = backtrack(nums, index + 1, currentSum + nums[index], target);
        int subtract = backtrack(nums, index + 1, currentSum - nums[index], target);
        
        return add + subtract;
    }
};

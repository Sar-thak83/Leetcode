// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int left = 0, sum = 0;
//         int minLen = INT_MAX;

//         for (int right = 0; right < n; right++) {
//             sum += nums[right];

//             // shrink the window while the condition is satisfied
//             while (sum >= target) {
//                 minLen = min(minLen, right - left + 1);
//                 sum -= nums[left];
//                 left++;
//             }
//         }

//         return (minLen == INT_MAX) ? 0 : minLen;
//     }
// };



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];  

                if (sum >= target) {
                    minLen = min(minLen, j - i + 1);
                    break; 
                }
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

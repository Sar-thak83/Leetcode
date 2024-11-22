// class Solution {
// public:
//     int matrixSum(vector<vector<int>>& nums) {
//         priority_queue<int>pq;
//         int n=nums[0].size();
//         int sum=0;
//         int j=0;
//         while(n>0)
//         {
//             for(int i=0;i<nums.size();i++)
//             {
//                 pq.push(nums[i][j]);
//             }
//             sum+=pq.top();
//             while(!pq.empty())
//             {
//                 pq.pop();
//             }
//             j++;
//             n--;
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sort(nums[i].begin(), nums[i].end());
        for (int j = 0; j <nums[0].size(); j++) {
            int maxnum = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                maxnum = max(maxnum, nums[i][j]);
            }
            sum = sum + maxnum;
        }
        return sum;
    }
};
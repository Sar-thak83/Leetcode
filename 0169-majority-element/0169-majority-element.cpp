// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         int count=0;
//         int checkele=0;
//         if(n==1)
//         {
//             return nums[0];
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(count==0)
//             {
//                 checkele=nums[i];
//                 count++;
//             }
//             else if(nums[i]==checkele)
//             {
//                 count++;
//             }
//             else if(nums[i]!=checkele)
//             {
//                 count--;
//             }
//         }
//         return checkele;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int n = nums.size();
        
        // Count frequencies
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }
        
        // Find majority element
        for(auto& pair : count){
            if(pair.second > n/2){
                return pair.first;
            }
        }
        
        return -1; // Should not reach here if majority guaranteed
    }
};
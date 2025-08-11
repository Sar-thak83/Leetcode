// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int>ans;
//         for(int i=0;i<numbers.size();i++){
//             for(int j=i+1;j<numbers.size();j++){
//                 if(numbers[i]+numbers[j]==target){
//                     ans.push_back(i+1);
//                     ans.push_back(j+1);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void binary_search(vector<int>&numbers, vector<int>& ans, int low,
                              int high, int target) {
        if (numbers[low] + numbers[high] == target) {
            ans.push_back(low + 1);
            ans.push_back(high + 1);

        } else if (numbers[low] + numbers[high] > target) {
            high--;
            binary_search(numbers, ans, low, high, target);
        } else {
            low++;
            binary_search(numbers, ans, low, high, target);
        }
        
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int low = 0;
        int high = numbers.size()-1;
        binary_search(numbers, ans, low, high, target);
        return ans;
    }
};
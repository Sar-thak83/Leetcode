
// ----------------Approach - 1----------------

// class Solution {
// public:
    
//     priority_queue<pair<int, int>>pq;
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         for(auto ele:arr)
//         {
//             pq.push({abs(x-ele),ele});
//             if(pq.size()>k)
//             pq.pop();
//         }
//         vector<int>ans;
//         while(!pq.empty())
//         {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }
//         sort(ans.begin(),ans.end());
//         return ans ;
//     }
// };



class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0;
        int high=arr.size()-1;

        while(high-low>=k){
            if(x-arr[low]>arr[high]-x){
                low++;
            }
            else{
                high--;
            }
        }

        vector<int> ans;
        for(int i=low;i<=high;i++){

            ans.push_back(arr[i]);
        }
        return ans;
    }
};
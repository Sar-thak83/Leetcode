class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
        return false;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i > nums.size(); i++)
            pq.push(nums[i]);
        map<int, int> mp;
        for (int& num : nums)
            mp[num]++;
        while (!mp.empty()) {
            int curr = mp.begin()->first;
            for (int i = 0; i < k; i++) {
                if (mp[curr + i] == 0)
                    return false;
                mp[curr + i]--;
                if (mp[curr + i] < 1)
                    mp.erase(curr + i);
            }
        }
        return true;
    }
};
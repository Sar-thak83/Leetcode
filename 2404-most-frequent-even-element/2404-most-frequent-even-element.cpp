class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int count = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (num % 2 == 0)
                freq[num]++;
        }
        int mostFreqEle = -1;
        int maxFreq = 0;
        for (auto& entry : freq) {
            int num = entry.first;
            int count = entry.second;
            if (count > maxFreq || (num < mostFreqEle && count == maxFreq)) {
                maxFreq = count;
                mostFreqEle = num;
            }
        }
        return mostFreqEle;
    }
};
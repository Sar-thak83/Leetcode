class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>seen;
        int maxlen=0;
        int left=0;
        for(int i=0;i<s.length();i++){
            char currChar=s[i];
            if(seen.count(currChar)&& seen[currChar]>=left){
                left=seen[currChar]+1;
            }
            seen[currChar]=i;
            maxlen=max(maxlen,i-left+1);
        }
        return maxlen;
    }
};

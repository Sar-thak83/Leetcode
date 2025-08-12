class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.size() == 0)
            return ans;
        for(int i=0;i<strs[0].length();i++){
            char currChar=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].length() || strs[j][i]!=currChar){
                    return ans;
                }
            }
            ans=ans+currChar;
        }
        return ans;
    }
};
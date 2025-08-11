class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        int count = 0;
        for (int i = 0; i < t.length(); i++) {
            if (s[j] == t[i]) {
                count = count + 1;
                j++;
            }
        }
        if (count != s.length())
            return false;
        return true;
    }
};
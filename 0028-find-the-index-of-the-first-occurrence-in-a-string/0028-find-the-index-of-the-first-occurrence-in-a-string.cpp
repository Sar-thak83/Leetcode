class Solution {
public:
    int strStr(string haystack, string needle) {
        string temp = "";
        int n = haystack.length();
        int m = needle.length();
        int i;
        for (i = 0; i <= n - m; i++) {   
            temp = "";                   
            for (int j = i; j < i + m; j++) {   
                temp += haystack[j];
            }
            if (temp == needle) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        int count[128] = {0};
        int windowCounts[128] = {0};

        for (char c : t) count[c]++;

        int required = 0;
        for (int i = 0; i < 128; ++i)
            if (count[i] > 0) required++;

        int formed = 0;
        int left = 0, right = 0;
        int minLen = INT_MAX, minStart = 0;

        while (right < (int)s.length()) {
            char c = s[right];
            windowCounts[c]++;
            if (count[c] > 0 && windowCounts[c] == count[c])
                formed++;

            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCounts[leftChar]--;
                if (count[leftChar] > 0 && windowCounts[leftChar] < count[leftChar])
                    formed--;

                left++;
            }
            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};

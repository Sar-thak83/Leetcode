class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c_to_s;
        unordered_map<string, char> s_to_c;
        vector<string> words;
        string word = "";
        for (char ch : s) {
            if (ch == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        if (words.size() != pattern.size())
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (c_to_s.count(c) && c_to_s[c] != w)
                return false;
            if (s_to_c.count(w) && s_to_c[w] != c)
                return false;
            c_to_s[c] = w;
            s_to_c[w] = c;
        }
        return true;
    }
};

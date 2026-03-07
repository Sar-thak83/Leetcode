class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = s + s;

        int start0 = 0, start1 = 0;
        int ans = INT_MAX;

        for(int i = 0; i < 2*n; i++) {

            if(i % 2 == 0){
                if(s[i] == '1') start0++;
                if(s[i] == '0') start1++;
            } 
            else{
                if(s[i] == '0') start0++;
                if(s[i] == '1') start1++;
            }

            if(i >= n){
                int j = i - n;

                if(j % 2 == 0){
                    if(s[j] == '1') start0--;
                    if(s[j] == '0') start1--;
                } 
                else{
                    if(s[j] == '0') start0--;
                    if(s[j] == '1') start1--;
                }
            }

            if(i >= n - 1){
                ans = min(ans, min(start0, start1));
            }
        }

        return ans;
    }
};
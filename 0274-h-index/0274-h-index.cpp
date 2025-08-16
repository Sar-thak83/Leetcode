class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int maxH = 0;
        for (int h = 1; h <= n; h++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (citations[i] >= h) {
                    count++;
                }
            }
            if (count >= h) {
                maxH = h;
            }
        }
        
        return maxH;
    }
};
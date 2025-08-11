class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int ans = 0;
        while (low < high) {
            int temp;
            if (height[low] > height[high]) {
                temp=height[high] * (high-low);
                ans = max(temp, ans);
                high--;
            }
            else{
                temp=height[low] * (high-low);
                ans = max(temp, ans);
                low++;
            }
        }
        return ans;
    }
};
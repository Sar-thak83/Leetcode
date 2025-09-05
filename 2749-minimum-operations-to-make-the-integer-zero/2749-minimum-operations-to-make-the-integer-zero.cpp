class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; k++) {
            long long x = (long long)num1 - 1LL * k * num2;
            if (x < 0) break;
            int fewestBlocks = __builtin_popcountll(x);
            if (fewestBlocks <= k && k <= x) {
                return k;
            }
        }
        return -1;
    }
};

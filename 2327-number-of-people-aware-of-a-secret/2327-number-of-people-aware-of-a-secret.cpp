class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;

        vector<long long> start(n + 2, 0), end(n + 2, 0);
        start[1 + delay] = 1;
        end[1 + forget] = 1;

        long long share = 0, total = 1;

        for (int day = 2; day <= n; day++) {
            share = (share + start[day] - end[day] + MOD) % MOD;
            total = (total + share) % MOD;

            if (share > 0) {
                if (day + delay <= n)
                    start[day + delay] = (start[day + delay] + share) % MOD;
                if (day + forget <= n)
                    end[day + forget] = (end[day + forget] + share) % MOD;
            }
        }

        long long forgotten = 0;
        for (int i = 1; i <= n; i++) {
            forgotten = (forgotten + end[i]) % MOD;
        }

        return (total - forgotten + MOD) % MOD;
    }
};
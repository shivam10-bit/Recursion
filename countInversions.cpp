class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        const int MOD = 1e9 + 7;

        vector<int> req(n, -1);
        int maxInv = 0;

        for (auto &r : requirements) {
            req[r[0]] = r[1];
            maxInv = max(maxInv, r[1]);
        }

        // prefix of length 1 can only have 0 inversions
        if (req[0] > 0) return 0;
        req[0] = 0;

        vector<vector<long long>> dp(
            n,
            vector<long long>(maxInv + 1, 0)
        );

        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {

            int L = 0;
            int R = maxInv;

            if (req[i] != -1) {
                L = R = req[i];
            }

            for (int inv = L; inv <= R; inv++) {

                for (int add = 0;
                     add <= min(i, inv);
                     add++) {

                    dp[i][inv] =
                        (dp[i][inv] +
                         dp[i - 1][inv - add]) % MOD;
                }
            }
        }

        return dp[n - 1][req[n - 1]];
    }
};
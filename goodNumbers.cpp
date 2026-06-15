class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        if (n == 0) return 1;

        if (n % 2 == 1)
            return (x * power(x, n - 1)) % MOD;

        return power((x * x) % MOD, n / 2);
    }

    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) *
                power(4, n / 2)) % MOD;
    }
};
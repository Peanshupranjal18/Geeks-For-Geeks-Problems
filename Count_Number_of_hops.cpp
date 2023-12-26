Memoization solution for number of hops question

long long fn(int sum,vector<int> &dp)
{
    if (sum == 0)
    {
        return 1;
    }
    if (sum < 0)
    {
        return 0;
    }
    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    long long mod = 1e9 + 7L;
    int res = (fn(sum - 1, dp) % mod + fn(sum - 2, dp) % mod + fn(sum - 3, dp) % mod) % mod;

    return dp[sum] = res;
    // return res;
}
long long countWays(int n)
{
    vector<int> dp(n + 1, -1);
    return fn(n, dp);
}

Tabulation solution for the number of hops question


long long countWays(int n)
{
    int mod = 1000000007;
    long long dp[n + 1];
    dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
        dp[i] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] += dp[i - 1] % mod;
        if (i > 1)
            dp[i] += dp[i - 2] % mod;
        if (i > 2)
            dp[i] += dp[i - 3] % mod;
    }
    return dp[n] % mod;
}
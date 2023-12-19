// Back-end complete function Template for C++
class Solution
{
public:
    const int mod = 1e9 + 7;
    int nthFibonacci(int n)
    {
        // prestoring
        int dp[n + 5];
        // initializing dp[0] as 0
        dp[0] = 0;
        // initializing dp[1] as 1
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            // as same as fibonacci formula f(i)=f(i-1)+f(i-2)
            dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
        }
        // returning nth value
        return dp[n];
    }
};

// space optimised approach

class Solution
{
public:
    int nthFibonacci(int n)
    {
        int n1 = 1, n2 = 1;
        if (n == 1 or n == 2)
            return 1;
        int ans = -1;
        int n3;
        for (int i = 2; i < n; i++)
        {
            n3 = (n1 + n2) % 1000000007;
            ans = n3;
            n1 = n2;
            n2 = n3;
        }
        return ans;
    }
};
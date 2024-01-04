// Dp approach for the problem

// Ya to number double ho jaye ya phir number ko +1 kar de

// O(n) approach

#include <vector>
#include <climits>

class Solution
{
public:
    int minOperation(int n)
    {
        if (n == 1)
            return 1;

        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = std::min(dp[i], dp[i - 1] + 1);
            if (i * 2 <= n)
            {
                dp[i * 2] = std::min(dp[i * 2], dp[i] + 1);
            }
        }

        return (dp[n] == INT_MAX) ? -1 : dp[n];
    }
};

// O(log n) approach

class Solution
{
public:
    int minOperation(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            n = (n % 2) ? n - 1 : n / 2;
            ans++;
        }
        return ans;
    }
};

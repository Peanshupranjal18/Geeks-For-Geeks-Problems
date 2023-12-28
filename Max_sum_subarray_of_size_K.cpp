Solution is similar to the problem Chocolate Distribution problem where we have to create a sliding window
    of size K.I have made use of deque to implement sliding window but the use of sliding window is not necessary

    class Solution
{
public:
#define ll long long
    long maximumSumSubarray(int k, vector<int> &a, int n)
    {
        deque<ll> q;
        ll i = 0;
        ll sum = 0;
        for (; i < k; i++)
        {
            q.push_back(a[i]);
            sum += a[i];
        }
        ll ans = sum;
        for (; i < n; i++)
        {
            sum -= q.front();
            q.pop_front();
            q.push_back(a[i]);
            sum += a[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};

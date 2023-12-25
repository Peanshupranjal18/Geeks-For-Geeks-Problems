class Solution
{
public:
    int isPerfectNumber(long long N)
    {
        int i = 1;
        int sum = 0;
        int k;
        if (N == 1)
        {
            return 0;
        }
        while (i <= ceil(sqrt(N)))
        {
            if (N % i == 0)
            {
                sum += i;
                k = i;
            }
            i++;
        }
        if (sum == N)
        {
            return 1;
        }
        if (N / sum == k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
// Important Sliding window technique and general implementation for
// Sliding window technique

class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int a = 0, b = 0;
        int ans = INT_MAX;
        int sum = 0;

        while (b < n)
        {
            sum += arr[b];

            while (sum > x)
            {
                ans = std::min(ans, b - a + 1);
                sum -= arr[a];
                a++;
            }

            b++;
        }

        return (ans != INT_MAX) ? ans : 0; // Return 0 if no subarray is found
    }
};
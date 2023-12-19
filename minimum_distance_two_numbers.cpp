// first from left and then from right

class Solution
{
public:
    int minDist(int a[], int n, int x, int y)
    {
        int pos = -1;
        int out = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
                pos = i;
            if (a[i] == y and pos >= 0)
                out = min(out, i - pos);
        }
        pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == y)
                pos = i;
            if (a[i] == x and pos >= 0)
                out = min(out, i - pos);
        }
        return out == INT_MAX ? -1 : out;
    }
};

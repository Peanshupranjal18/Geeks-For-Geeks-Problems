// Binary Search Important Concept Linear Search is not required for this question

class Solution
{
public:
    int findExtra(int a[], int b[], int n)
    {
        // add code here.
        int s = 0;
        int e = n - 2;
        int ans = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (b[mid] == a[mid])
            {
                s = mid + 1;
            }
            else
            {
                if (b[mid - 1] == a[mid])
                {
                    ans = mid;
                    e = mid - 1;
                }
                else
                    return mid;
            }
        }
        return ans;
    }
};
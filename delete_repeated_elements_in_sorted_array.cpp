// two pointer method
// using two variable

class Solution
{
public:
    int remove_duplicate(int a[], int n)
    {
        int count = 0;
        int value = a[0];
        for (int i = 1; i < n; i++)
        {
            if (value != a[i])
            {
                count++;
                a[count] = a[i];
                value = a[i];
            }
        }
        return count + 1;
    }
};
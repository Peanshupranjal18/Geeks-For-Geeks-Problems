Alternate postioning of the positive and negative elements
    Important concept

    class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                pos.push_back(arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                neg.push_back(arr[i]);
            }
        }
        int i = 0, j = 0, k = 0;
        while (i < pos.size() && j < neg.size())
        {
            arr[k] = pos[i];
            i++;
            k++;
            arr[k] = neg[j];
            j++;
            k++;
        }

        // for remaining elements

        while (i < pos.size())
        {
            arr[k] = pos[i];
            i++;
            k++;
        }
        while (j < neg.size())
        {
            arr[k] = neg[j];
            j++;
            k++;
        }
    }
};
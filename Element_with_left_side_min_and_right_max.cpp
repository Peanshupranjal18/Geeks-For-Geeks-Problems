int findElement(int arr[], int n)
{

    if (n <= 2)
        return -1;

    vector<int> left;
    vector<int> right;

    int max = INT_MIN;
    int min = INT_MAX;

    // left max banana har ke liye

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
        }
        left.push_back(max);
    }

    // right min banana har ekement in array ke liye

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
        }
        right.push_back(min);
    }

    reverse(right.begin(), right.end());

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= left[i] && arr[i] <= right[i])
            return arr[i];
    }
    return -1;
}
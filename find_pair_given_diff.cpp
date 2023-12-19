// unordered map important concept application

bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        int a = arr[i];
        int b = abs(arr[i] - n);
        int c = arr[i] + n;

        if (mp.find(b) != mp.end() || mp.find(c) != mp.end())
            return true;

        mp[a] = i;
    }

    return false;
}
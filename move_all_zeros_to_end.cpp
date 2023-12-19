// two pointer approach to have the zeros in the end

void pushZerosToEnd(int arr[], int n)
{
    // code here
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] == 0)
        {
            j++;
            continue;
        }
        else
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
    }
}
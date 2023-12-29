// Row-wise and Column-Wise sorted approach

class Solution
{
public:
    int matSearch(vector<vector<int>> &mat, int N, int M, int X)
    {
        int i = 0, j = M - 1;
        while (i >= 0 && j >= 0 && i < N)
        {
            if (mat[i][j] == X)
                return true;
            if (mat[i][j] > X)
                j--;
            else
                i++;
        }
        return 0;
    }
};

Expected Approach according to the editorial

    class Solution
{
public:
    // Function to search for an element in a matrix.
    int matSearch(vector<vector<int>> &arr, int n, int m, int x)
    {
        int r = 0, c = m - 1;

        // iterating until we reach the end of the rows or columns.
        while (r < n and c >= 0)
        {
            // if the current element is equal to the target element, return 1.
            if (arr[r][c] == x)
                return 1;

            // if the current element is greater than the target element,
            // decrease the column index.
            if (arr[r][c] > x)
                c--;

            // if the current element is less than the target element,
            // increase the row index.
            else
                r++;
        }
        // if the target element is not found in the matrix, return 0.
        return 0;
    }
};

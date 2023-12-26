Efficient Solution

// C++ program to find all pair in both arrays
// whose sum is equal to given value x
#include <bits/stdc++.h>
    using namespace std;

// Function to find all pairs in both arrays
// whose sum is equal to given value x
void findPairs(int arr1[], int arr2[], int n,
               int m, int x)
{
    // Insert all elements of first array in a hash
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr1[i]);

    // Subtract sum from second array elements one
    // by one and check it's present in array first
    // or not
    for (int j = 0; j < m; j++)
        if (s.find(x - arr2[j]) != s.end())
            cout << x - arr2[j] << " "
                 << arr2[j] << endl;
}

// Driver code
int main()
{
    int arr1[] = {1, 0, -4, 7, 6, 4};
    int arr2[] = {0, 2, 4, -3, 2, 1};
    int x = 8;
    int n = sizeof(arr1) / sizeof(int);
    int m = sizeof(arr2) / sizeof(int);
    findPairs(arr1, arr2, n, m, x);
    return 0;
}

My Solution

    class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int, int>> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
            mp[A[i]]++;
        for (int i = 0; i < M; i++)
        {
            if (mp[X - B[i]] > 0)
            {
                ans.push_back({X - B[i], B[i]});
                mp[X - B[i]]--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};